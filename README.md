# k0 — Kotlin Subset Compiler

> A from-scratch compiler frontend for **K0**, a statically-typed subset of Kotlin, built for CSE 423 Compilers at New Mexico Tech. Implements a complete lexer, parser, and parse-tree printer with zero grammar conflicts.

---

## Table of Contents

- [Overview](#overview)
- [Language Features](#language-features)
- [Project Structure](#project-structure)
- [Architecture](#architecture)
- [Building](#building)
- [Usage](#usage)
- [Grammar Design](#grammar-design)
- [Automatic Semicolon Insertion](#automatic-semicolon-insertion)
- [Token Reference](#token-reference)
- [Known Limitations](#known-limitations)
- [Example Output](#example-output)

---

## Overview

K0 ("Kay Zero") is a tiny but non-trivial subset of Kotlin — roughly the features you'd cover in a CS1 course. Every valid K0 program is also a valid Kotlin program. The compiler frontend accepts `.kt` source files and produces a printed parse tree.

The parser is built with **Bison (LALR(1))** and the lexer with **Flex**, connected by a custom Automatic Semicolon Insertion (ASI) layer that mirrors Kotlin's newline-sensitive grammar rules. The final grammar has **0 shift/reduce conflicts and 0 reduce/reduce conflicts**.

---

## Language Features

### Types
| Syntax | Example |
|--------|---------|
| Primitive | `Int`, `Double`, `Boolean`, `String`, `Char`, `Long`, `Float`, `Byte`, `Short` |
| Nullable | `Int?`, `String?` |
| Generic | `Array<Int>`, `Array<String>`, `Array<Int>?` |
| Nested generic | `Array<Array<Int>>`, `Map<String, Int>` |

> **Note:** Generic types are supported in all type-annotation positions (after `:`). Generic constructor calls in expressions (e.g. `Array<Int>(5)`) are not parseable — see [Known Limitations](#known-limitations).

### Declarations
```kotlin
val x: Int = 10          // immutable
var y = 20               // mutable, inferred
const val MAX = 100      // compile-time constant
var arr: Array<Int>      // generic type annotation
```

### Functions
```kotlin
fun greet(name: String): String { ... }   // with return type
fun main() { ... }                         // no return type
fun main(args: Array<String>) { ... }      // spec entry point
fun double(x: Int) = x * 2                // single-expression body
fun add(x: Int = 0, y: Int = 0): Int { .. } // default parameters
```

### Control Flow
```kotlin
// if / else-if / else
if (x > 0) { ... } else if (x < 0) { ... } else { ... }

// while
while (i > 0) { i-- }

// do-while
do { x++ } while (x < 10)

// for-in (range)
for (i in 1..10) { ... }

// for-in (typed iterator)
for (x: Int in arr) { ... }

// range-until
for (i in 0..<10) { ... }

// when (with and without subject)
when (x) { 1 -> ... else -> ... }
when { x > 0 -> ... else -> ... }
```

### Operators
| Category | Operators |
|----------|-----------|
| Arithmetic | `+` `-` `*` `/` `%` |
| Assignment | `=` `+=` `-=` `*=` `/=` `%=` |
| Comparison | `==` `!=` `<` `>` `<=` `>=` `===` `!==` |
| Logical | `&&` `\|\|` `!` |
| Unary prefix | `-` `+` `!` |
| Postfix | `++` `--` (postfix only per spec) |
| Elvis / null-safe | `?:` `?.` |
| Range | `..` `..<` |
| In-range | `in` |
| Cast | `as` |
| Member / call | `.` `?.` `::` `[]` `()` |

### Expressions
```kotlin
val result = a + b * c - d / e % f    // arithmetic precedence
val safe = s?.length                   // safe call
val fallback = value ?: "default"      // elvis
val r = x in 1..100                   // in-range
val cast = x as Int                    // type cast
val ref = String::length               // double-colon ref
val arr = [1, 2, 3]                   // collection literal
```

### Jump Statements
```kotlin
return          // void return
return expr     // value return
break
continue
```

---

## Project Structure

```
Lab4/
├── k0gram.y        # Bison grammar — LALR(1), 0 conflicts
├── k0lex.l         # Flex lexer
├── asi.c           # Automatic Semicolon Insertion wrapper
├── tree.c          # Parse tree construction and printing
├── tree.h          # Tree node types
├── token.h         # Token struct definition
├── prodrule.h      # Production rule constants (R_* enums)
├── Makefile        # Build rules
├── Test_full_v2.kt # Full-coverage test (38 functions)
└── Test_generics.kt # Targeted generic-type tests (13 functions)
```

---

## Architecture

```
Source file (.kt)
      │
      ▼
┌─────────────┐
│  k0lex.l    │  Flex lexer — tokenizes source, tracks line numbers,
│  (Flex)     │  handles comments, string/char escapes, literal values
└──────┬──────┘
       │  flex_yylex()  ← renamed so ASI can wrap it
       ▼
┌─────────────┐
│   asi.c     │  Automatic Semicolon Insertion — intercepts NEWLINEs,
│   (C)       │  emits SEMI tokens based on Kotlin's ASI rules,
└──────┬──────┘  handles do-while RCURL special case
       │  yylex()
       ▼
┌─────────────┐
│  k0gram.y   │  Bison LALR(1) parser — builds parse tree via
│  (Bison)    │  alloktree() / leafnode() calls in semantic actions
└──────┬──────┘
       │
       ▼
┌─────────────┐
│   tree.c    │  treeprint() — walks the parse tree and prints
│   (C)       │  it as an indented, Unicode box-drawing tree
└─────────────┘
```

### Token Flow

Each token matched by the lexer calls `make_token()`, which:
1. Populates the global `yytoken` struct (`category`, `text`, `lineno`, `filename`)
2. Allocates a heap-owned copy for the parse tree leaf (so nodes don't alias the overwritten global)
3. Calls `leafnode()` to wrap it in a tree node
4. Assigns it to `yylval.treeptr`

String literals are additionally processed through `unescape_string()` to handle `\n`, `\t`, `\"`, `\\`, etc.

---

## Building

**Requirements:** `gcc`, `bison`, `flex`, `make`

```bash
make              # build the k0 binary
make clean        # remove all generated files
```

The Makefile runs:
```
bison -d k0gram.y          → k0gram.tab.c, k0gram.tab.h
flex k0lex.l               → lex.yy.c
gcc k0gram.tab.c lex.yy.c asi.c tree.c -o k0
```

To inspect grammar conflicts (should report none):
```bash
bison -d k0gram.y 2>&1
bison -d k0gram.y -Wcounterexamples 2>&1
```

---

## Usage

```bash
./k0 <file.kt>               # parse and print tree to stdout
./k0 <file.kt> > tree.txt    # capture output to file
./k0 <file.kt> 2>/dev/null   # suppress LEAF lines (stderr), show tree only
```

### Output format

Every token is printed to stderr as it is lexed:
```
LEAF: category=258 text=fun line=1 file=hello.kt
```

On successful parse, the full tree is printed to stdout:
```
program
└─ function_declaration
   ├─ 258:FUN `fun`
   ├─ 282:IDENT `main`
   ├─ function_value_parameters
   │  ├─ 312:LPAREN `(`
   │  └─ 313:RPAREN `)`
   └─ block
      ...
```

Exit codes: `0` = success, `2` = parse error.

---

## Grammar Design

### Conflict Resolution

The grammar was developed iteratively from 97 shift/reduce and 58 reduce/reduce conflicts down to zero.

| Fix | Conflict removed | What changed |
|-----|-----------------|--------------|
| 1 | ~30 S/R on expression LHS | Changed `expression: expression = expression` to `expression: disjunction = expression` |
| 2 | ~20 R/R on if/when | Removed `if_expression` and `when_expression` from `primary_expr`; added them directly to `statement` and `control_structure_body` |
| 3 | ~20 S/R in when entries | Made SEMI required after `when_entry` body (ASI always provides it) |
| 4 | 20 R/R + useless rule | Removed explicit `ELSE if_expression` rule — covered by `ELSE control_structure_body → if_expression` |
| 5 | 3 S/R in do-while | Changed `DO optional_body WHILE` to `DO block WHILE \| DO SEMI WHILE` |
| 6 | 1 S/R in value_argument | Removed named-argument form — `IDENT = expr` is already an assignment expression |
| 7 | 1 S/R on LANGLE after AS | Split `type` into `type` (bare, used only in `as_expr`) and `full_type` (generic-capable, used in all `:` contexts) |

### Expression Tower (lowest → highest precedence)

```
expression          =  +=  -=  *=  /=  %=    (right-assoc, LHS: disjunction)
disjunction         ||
conjunction         &&
equality_expr       ==  !=  ===  !==
comparison_expr     <  >  <=  >=
infix_operation     in
elvis_expr          ?:
range_expr          ..  ..<
additive_expr       +  -
multiplicative_expr *  /  %
as_expr             as                        (uses bare `type`)
prefix_expr         !  -  +  ++  --           (right-assoc unary)
postfix_expr        ++  --  .  ?.  ::  []  () (highest)
primary_expr        literals, IDENT, (expr), []
```

### Type System Split

Generic types require splitting `type` into two nonterminals to avoid an LALR(1) ambiguity where `IDENT < ...` after `as` could be either a generic bracket or a comparison operator:

```
type      — bare only (IDENT, IDENT?)            used in: as_expr AS type
full_type — generic-capable                       used in: all COLON contexts

full_type:
    IDENT
    IDENT QUEST                          e.g. Int?
    IDENT LANGLE type_args RANGLE        e.g. Array<Int>
    IDENT LANGLE type_args RANGLE QUEST  e.g. Array<Int>?

type_args:
    full_type
    type_args COMMA full_type            e.g. Map<String, Int>
```

---

## Automatic Semicolon Insertion

`asi.c` wraps the Flex-generated `flex_yylex()` (renamed via `#define YY_DECL`) and implements Kotlin's newline-as-semicolon rule.

### Tokens that trigger SEMI on newline

```
IDENT
INTEGERLITERAL  LONGLITERAL  REALLITERAL  DOUBLELITERAL
BOOLEANLITERAL  CHARACTERLITERAL  STRINGLITERAL  NULLLITERAL
RETURN  BREAK  CONTINUE
INCR  DECR  RPAREN  RSQUARE
RCURL   ← special case
```

### RCURL / do-while special case

`RCURL` must trigger SEMI so statements after block bodies are separated — but in `do { } while(...)`, the `}` and `while` are on the same conceptual unit and must not get a SEMI between them.

**Solution:** SEMI is suppressed when `last_tok == RCURL` and the next real token is `WHILE`:

```c
if (last_tok == RCURL && next == WHILE) {
    return WHILE;   // do-while — no SEMI inserted
}
```

### LCURL suppression

SEMI is never emitted before `{`, so patterns like:

```kotlin
fun foo()
{
```

...do not produce a spurious SEMI before the opening brace.

---

## Token Reference

### Keywords
```
FUN  VAL  VAR  IF  ELSE  WHILE  FOR  RETURN  BREAK  CONTINUE
WHEN  IN  DO  IMPORT  CONST  AS
```

### Literals
```
INTEGERLITERAL   — decimal integers, e.g. 42
LONGLITERAL      — long integers with L suffix, e.g. 100L
REALLITERAL      — simple reals, e.g. 3.14
DOUBLELITERAL    — doubles with optional D/d suffix
BOOLEANLITERAL   — true | false
CHARACTERLITERAL — single character in apostrophes, e.g. 'z'
STRINGLITERAL    — double-quoted string, escape sequences processed
NULLLITERAL      — null
```

### Identifiers
```
[a-zA-Z_][a-zA-Z0-9_]*    C-style identifiers (not full Kotlin Unicode rules)
```

### Operators
```
=   +=  -=  *=  /=  %=           assignment
+   -   *   /   %                 arithmetic
++  --                            increment / decrement
==  !=  <   >   <=  >=            comparison
=== !==                           referential equality
&&  ||  !                         logical
?.  ?:  ?                         null-safety
..  ..<                           range / range-until
->  ::                            arrow / double-colon
```

### Punctuation
```
(  )   — LPAREN / RPAREN
{  }   — LCURL / RCURL
[  ]   — LSQUARE / RSQUARE
,  .   — COMMA / DOT
:  ;   — COLON / SEMI (SEMI usually inserted by ASI, not written explicitly)
```

---

## Known Limitations

| Feature | Status |
|---------|--------|
| `Array<Int>(5)` constructor call in expressions | **Not supported** — `IDENT < T >` in expression context is indistinguishable from chained comparisons in LALR(1) |
| Lambda / trailing lambdas `{ x -> ... }` | Not supported |
| Named arguments `foo(x = 1)` | Removed — duplicates assignment expression |
| String templates `"Hello $name"` | Treated as opaque `STRINGLITERAL` |
| Classes / objects | Not in K0 spec |
| Extension functions | Not in K0 spec |
| Unsigned integer literals | Lexer reports error |
| Scientific notation `1e10` | Lexer reports error |
| Nested `/* */` comments | Not supported (Kotlin allows nesting; K0 does not) |

---

## Example Output

```kotlin
fun add(x: Int, y: Int): Int {
    return x + y
}
```

```
program
└─ top_level_object_list
   └─ function_declaration
      ├─ 258:FUN `fun`
      ├─ 282:IDENT `add`
      ├─ function_value_parameters
      │  ├─ 312:LPAREN `(`
      │  ├─ function_value_parameter_list
      │  │  ├─ function_value_parameter
      │  │  │  ├─ 282:IDENT `x`
      │  │  │  ├─ 320:COLON `:`
      │  │  │  └─ 282:IDENT `Int`
      │  │  ├─ 318:COMMA `,`
      │  │  └─ function_value_parameter
      │  │     ├─ 282:IDENT `y`
      │  │     ├─ 320:COLON `:`
      │  │     └─ 282:IDENT `Int`
      │  └─ 313:RPAREN `)`
      ├─ optional_return_type
      │  ├─ 320:COLON `:`
      │  └─ 282:IDENT `Int`
      └─ block
         ├─ 314:LCURL `{`
         ├─ statements
         │  ├─ return_statement
         │  │  ├─ 265:RETURN `return`
         │  │  └─ additive_expr
         │  │     ├─ 282:IDENT `x`
         │  │     ├─ 289:ADD `+`
         │  │     └─ 282:IDENT `y`
         │  └─ 321:SEMI `;`
         └─ 315:RCURL `}`
```

---

## Running the Tests

```bash
# full language coverage (38 functions)
./k0 Test_full_v2.kt > out_full.txt 2>&1 && echo "PASS" || echo "FAIL"

# usual workflow
./k0 [YOUR KOTLIN TEST FILE HERE].kt > OUT.txt ||
./k0 [YOUR KOTLIN TEST FILE HERE].kt > OUT.txt 
./k0 [YOUR KOTLIN TEST FILE HERE].kt > OUT.txt 2>&1 && echo "PASS" || echo "FAIL"

# check for any syntax errors in output
grep -c "syntax error" out_full.txt      # should print 0
grep -c "syntax error" out_generics.txt  # should print 0
```

---

*CSE 423 Compilers — New Mexico Institute of Mining and Technology*
