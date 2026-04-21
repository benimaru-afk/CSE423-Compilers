# k0 — Kotlin Subset Compiler

> A from-scratch compiler frontend for **K0**, a statically-typed subset of Kotlin, built for CSE 423 Compilers at New Mexico Tech. Implements a complete lexer, parser, semantic analyzer, type checker, and three-address intermediate code generator with zero grammar conflicts.

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
- [Symbol Tables](#symbol-tables)
- [Type System](#type-system)
- [Semantic Analysis](#semantic-analysis)
- [Intermediate Code Generation](#intermediate-code-generation)
- [Token Reference](#token-reference)
- [Known Limitations](#known-limitations)
- [Example Output](#example-output)

---

## Overview

K0 ("Kay Zero") is a tiny but non-trivial subset of Kotlin — roughly the features you'd cover in a CS1 course. Every valid K0 program is also a valid Kotlin program. The compiler accepts `.kt` source files and produces a printed parse tree, symbol tables, type-checked semantic analysis, and three-address intermediate code in `.ic` files.

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

### Declarations
```kotlin
val x: Int = 10          // immutable
var y = 20               // mutable, inferred
const val MAX = 100      // compile-time constant
var arr: Array<Int>      // generic type annotation
```

### Functions
```kotlin
fun greet(name: String): String { ... }
fun main() { ... }
fun double(x: Int) = x * 2
fun add(x: Int = 0, y: Int = 0): Int { ... }
```

### Control Flow
```kotlin
if (x > 0) { ... } else if (x < 0) { ... } else { ... }
while (i > 0) { i-- }
do { x++ } while (x < 10)
for (i in 1..10) { ... }
for (x: Int in arr) { ... }
for (i in 0..<10) { ... }
when (x) { 1 -> ... else -> ... }
```

### Operators
| Category | Operators |
|----------|-----------|
| Arithmetic | `+` `-` `*` `/` `%` |
| Assignment | `=` `+=` `-=` `*=` `/=` `%=` |
| Comparison | `==` `!=` `<` `>` `<=` `>=` `===` `!==` |
| Logical | `&&` `\|\|` `!` |
| Unary prefix | `-` `+` `!` `++` `--` |
| Postfix | `++` `--` |
| Elvis / null-safe | `?:` `?.` |
| Range | `..` `..<` |
| Cast | `as` |
| Member / call | `.` `?.` `::` `[]` `()` |

---

## Project Structure

Layout of the repo follows the usual pattern of labs (exercises to expand the compiler) paired with homeworks (more in-depth assignments):

```
Compilers/
├── lab1 / hw1
├── lab2 / hw2
├── lab3 / hw3
├── lab4 / hw4        ← grammar, parse tree, symbol tables
├── lab5              ← type system
├── lab6              ← symbol table printing
├── lab7              ← type annotations in symbol tables
├── lab9              ← standalone TAC practice
└── hw5               ← type rules and correct semantics
└── hw6               ← semantic analysis, type checking, codegen
```

Current submission (`hw6`) contains:

```
hw6/
├── k0gram.y         # Bison grammar + main() — LALR(1), 0 conflicts
├── k0lex.l          # Flex lexer with debug_tokens guard
├── asi.c            # Automatic Semicolon Insertion wrapper
├── tree.c / tree.h  # Parse tree construction, printing; struct addr place field
├── token.h          # Token struct (category, text, lineno, filename, ival, dval, sval)
├── prodrule.h       # Production rule constants (R_* enums)
├── symtab.c / .h    # Hash-table symbol tables with type and place fields
├── symscan.c / .h   # Two-pass tree traversal: buildsyms() + checksyms()
├── type.c / .h      # Type system: typeinfo structs, singletons, constructors
├── typecheck.c / .h # Type, mutability, and nullability checking pass
├── tac.c / .h       # Three-address code data structures and tacprint()
├── codegen.c / .h   # TAC generation from parse tree, output_ic()
├── Makefile
└── test_cases/
    ├── Test_full_v2.kt    # Full-coverage test (38 functions)
    ├── hello.kt
    ├── valid.kt
    ├── errors.kt
    └── err_*.kt           # Individual semantic error test cases
```

---

## Architecture

```
Source file (.kt)
      │
      ▼
┌─────────────┐
│  k0lex.l    │  Flex lexer — tokenizes source, tracks line numbers,
│  (Flex)     │  handles comments, string/char escapes, literal values.
│             │  LEAF lines suppressed by default; enabled by -tree flag
│             │  via the debug_tokens global (extern int debug_tokens).
└──────┬──────┘
       │  flex_yylex()  ← renamed so ASI can wrap it
       ▼
┌─────────────┐
│   asi.c     │  Automatic Semicolon Insertion — intercepts NEWLINEs,
│   (C)       │  emits SEMI tokens per Kotlin's ASI rules,
└──────┬──────┘  suppresses SEMI before { and between } and while.
       │  yylex()
       ▼
┌─────────────┐
│  k0gram.y   │  Bison LALR(1) parser — builds parse tree via
│  (Bison)    │  alloktree() / leafnode() calls in semantic actions.
└──────┬──────┘  main() drives all subsequent passes.
       │ parseroot (struct tree *)
       ▼
┌─────────────┐
│  symscan.c  │  Pass 1 — buildsyms(): walks tree, populates per-scope
│             │  hash-table symbol tables, infers types from annotations
│             │  and literal initializers, assigns place (ADDR_NONE) stubs.
│             │  Pass 2 — checksyms(): reports undeclared identifiers,
│             │  annotates IDENT leaves with typeptr from symbol table.
└──────┬──────┘
       │
       ▼
┌─────────────┐
│ typecheck.c │  Pass 3 — typecheck(): walks tree enforcing:
│             │   • operator type compatibility (arithmetic needs numeric,
│             │     logical needs bool, ! needs bool)
│             │   • assignment type matching
│             │   • mutability (val/const cannot be reassigned)
│             │   • nullability (null → non-nullable is an error)
│             │   • if/while conditions must be boolean
│             │   • function call argument count
└──────┬──────┘
       │  (only if semantic_errors == 0)
       ▼
┌─────────────┐
│  codegen.c  │  Pass 4 — codegen(): synthesizes .place (struct addr)
│             │  on every expression node and builds a linked list of
│             │  TAC instructions (struct instr linked list).
│             │  output_ic() writes the .ic file to the current directory.
└──────┬──────┘
       │
       ▼
  foo.ic
  (.string / .data / .code regions)
```

### Token Flow

Each token matched by the lexer calls `make_token()`, which:

1. Populates the global `yytoken` struct (`category`, `text`, `lineno`, `filename`)
2. Allocates a heap-owned copy for the parse tree leaf so nodes don't alias the overwritten global
3. Calls `leafnode()` to wrap it in a `struct tree` node, initializing `stab = NULL`, `type = NULL`, `place = ADDR_NONE`
4. Assigns it to `yylval.treeptr`
5. Calls `printnode()` **only if** `debug_tokens == 1` (set exclusively by the `-tree` flag in `main()`)

Integer and float literals store their parsed values in `leaf->ival` and `leaf->dval`. String literals are processed through `unescape_string()` to handle `\n`, `\t`, `\"`, `\\`, etc.

---

## Building

**Requirements:** `gcc`, `bison`, `flex`, `make`

```bash
make              # build the k0 binary
make clean        # remove all generated files and .ic output files
```

The Makefile compiles each `.c` file to a separate `.o` with `-Wall -g`, then links:

```
bison -d k0gram.y          → k0gram.tab.c, k0gram.tab.h
flex k0lex.l               → lex.yy.c
gcc -Wall -g -c k0gram.tab.c
gcc -Wall -g -c lex.yy.c
gcc -Wall -g -c asi.c
gcc -Wall -g -c tree.c
gcc -Wall -g -c symtab.c
gcc -Wall -g -c symscan.c
gcc -Wall -g -c type.c
gcc -Wall -g -c typecheck.c
gcc -Wall -g -c tac.c
gcc -Wall -g -c codegen.c
gcc -Wall -g *.o -o k0
```

To inspect grammar conflicts (should always report none):
```bash
bison -d k0gram.y 2>&1
bison -d k0gram.y -Wcounterexamples 2>&1
```

**Expected output:** zero errors. Two harmless warnings from Flex-generated `lex.yy.c` about unused `input` and `yyunput` functions — these are internal to Flex and cannot be suppressed without modifying generated code.

---

## Usage

```bash
./k0 <file.kt>                  # parse, analyze, generate foo.ic
./k0 -tree <file.kt>            # also print parse tree + LEAF lines
./k0 -symtab <file.kt>          # also print symbol tables
./k0 -tree -symtab <file.kt>    # both
./k0 <file.kt> > out.txt 2>&1   # capture all output
./k0 <file.kt> 2>/dev/null       # suppress error messages, show only stdout
```

### Exit codes

| Code | Meaning |
|------|---------|
| 0 | No errors — `.ic` file written |
| 1 | Cannot open file |
| 2 | Syntax error |
| 3 | Semantic error (undeclared, type mismatch, mutability, nullability, etc.) |

### Output files

On success, the compiler writes `<basename>.ic` to the **current working directory** regardless of where the input file lives:

```bash
./k0 /some/path/to/foo.kt    # writes ./foo.ic, not /some/path/to/foo.ic
```

Stdout prints the filename on open and `No errors` on success. All error messages go to stderr.

---

## Grammar Design

### Conflict Resolution

| Fix | Conflicts removed | What changed |
|-----|-------------------|--------------|
| 1 | ~30 S/R on expression LHS | Changed `expression: expression = expression` to `expression: disjunction = expression` |
| 2 | ~20 R/R on if/when | Removed from `primary_expr`; added to `statement` and `control_structure_body` |
| 3 | ~20 S/R in when entries | Made SEMI required after `when_entry` body (ASI always provides it) |
| 4 | 20 R/R + useless rule | Removed explicit `ELSE if_expression` — covered by `ELSE control_structure_body` |
| 5 | 3 S/R in do-while | Changed to `DO block WHILE \| DO SEMI WHILE` |
| 6 | 1 S/R in value_argument | Removed named-argument form — already covered by assignment expression |
| 7 | 1 S/R on LANGLE after AS | Split `type` into bare `type` (used only in `as_expr`) and generic-capable `full_type` (used in all `:` contexts) |

### Expression Tower (lowest → highest precedence)

```
expression          =  +=  -=  *=  /=  %=    (right-assoc, LHS must be disjunction)
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
primary_expr        literals, IDENT, (expr), [], if, when
```

### Type System Split

To avoid an LALR(1) ambiguity where `IDENT < T >` after `as` could be either a generic bracket or a comparison operator, `type` is split into two nonterminals:

```
type      — bare only (IDENT, IDENT?)             used in: as_expr AS type
full_type — generic-capable                        used in: all COLON contexts

full_type:
    IDENT
    IDENT QUEST                           e.g.  Int?
    IDENT LANGLE type_args RANGLE         e.g.  Array<Int>
    IDENT LANGLE type_args RANGLE QUEST   e.g.  Array<Int>?

type_args:
    full_type
    type_args COMMA full_type             e.g.  Map<String, Int>
```

---

## Automatic Semicolon Insertion

`asi.c` wraps `flex_yylex()` and implements Kotlin's newline-as-semicolon rule. A SEMI is injected after a NEWLINE when the preceding token is any of:

```
IDENT, all literals (INT, LONG, REAL, DOUBLE, BOOL, CHAR, STRING, NULL),
RETURN, BREAK, CONTINUE, INCR, DECR, RPAREN, RSQUARE, RCURL
```

SEMI is suppressed before `{` (LCURL always swallows preceding SEMI) and when `RCURL` is immediately followed by `WHILE` (the do-while special case).

---

## Symbol Tables

Each scope gets a separate hash-table-based symbol table (`SYM_NBUCKETS = 64` buckets, chained with linked lists). Three scope levels:

- **Predefined** — stdlib (`println`, `print`, `readln`, `abs`, `max`, `min`, `pow`, `cos`, `sin`, `tan`) and type names (`Int`, `String`, `Boolean`, etc.)
- **Global** — top-level function names and `const val` declarations; entries assigned `R_GLOBAL` offsets
- **Per-function local** — parameters, `val`/`var`/`const val` locals, for-loop iterators; entries assigned `R_LOCAL` offsets

Each `sym_entry` stores:

| Field | Type | Purpose |
|-------|------|---------|
| `name` | `char *` | symbol string |
| `type` | `typeptr` | full type information |
| `is_const` | `int` | 1 if `const val` |
| `is_mutable` | `int` | 1 if `var` |
| `lineno` | `int` | declaration line |
| `filename` | `char *` | declaration file |
| `place` | `struct addr` | memory address (region + offset) for codegen |

---

## Type System

`type.h` defines `struct typeinfo` with `basetype`, `nullable` flag, and a union for function/array subtypes.

| Constant | K0 type(s) |
|----------|-----------|
| `INT_TYPE` | Int, Long, Short, Byte |
| `FLOAT_TYPE` | Double, Float |
| `BOOL_TYPE` | Boolean |
| `CHAR_TYPE` | Char |
| `STRING_TYPE` | String |
| `ARRAY_TYPE` | Array\<T\>, List, Map, Set |
| `FUNC_TYPE` | function declarations |
| `ANY_TYPE` | Any, unknown |
| `NULL_TYPE` | `null` literal |
| `NONE_TYPE` | unresolved / void / Unit |

Scalar types use singleton `typeptr` instances (e.g. `integer_typeptr`). `typename_to_typeptr()` maps K0 type name strings from the parse tree to the correct singleton. `val x = null` with no annotation is stored as nullable `ANY_TYPE`.

---

## Semantic Analysis

Three passes run in sequence inside `main()` after a successful parse:

**Pass 1 — `buildsyms()`** populates symbol tables by walking the parse tree. Explicit type annotations are extracted from `optional_type_annotation` / `full_type` subtrees. Type is inferred from literal initializers when no annotation is present (`val x = 5` → `INT_TYPE`). Function types are built with `alcfunctype(local_scope, return_type)`.

**Pass 2 — `checksyms()`** walks the tree a second time. Import paths, type annotation nodes, declaration name positions, and member names after `.`/`?.`/`::` are skipped to avoid false positives. Every other `IDENT` leaf is looked up via `lookupsym_chain()` and annotated with `t->type`.

**Pass 3 — `typecheck()`** enforces type rules:

- Arithmetic operands must be numeric (`INT_TYPE` or `FLOAT_TYPE`)
- `&&`, `||`, `!` operands must be `BOOL_TYPE`
- `if` / `while` conditions must be `BOOL_TYPE`
- Assignment to `val` or `const val` is an error
- Type mismatches in declarations and assignments are errors
- `null` cannot be assigned to a non-nullable declared type

---

## Intermediate Code Generation

Pass 4 is implemented in `codegen.c`. It walks the parse tree recursively, building a singly-linked list of `struct instr` nodes and setting `t->place` (a `struct addr`) on every expression subtree.

### Memory regions

| Region constant | Description |
|----------------|-------------|
| `R_LOCAL` | Stack frame locals, params, temporaries (offset from base pointer) |
| `R_GLOBAL` | Global variables (offset from global data area) |
| `R_CONST` | Immediate integer/boolean value (stored in offset field) |
| `R_STRING` | Offset into the `.string` region |
| `R_NAME` | Symbolic name (used for `call` targets) |
| `R_NONE` | Unused / void address |

All values are **8 bytes**. `assign_offsets(scope, region)` walks the hash table and assigns sequential 8-byte offsets. Temporaries are allocated by `new_temp()` starting just past the last named local (`frame_base = nEntries * 8`).

### Output file format

```
.string  <total-bytes>
    <string-content>\000        ← NUL-terminated; non-printables as \ooo octal
.data
    <name>  8                   ← global variable, 8 bytes each
.code
<funcname>:                     ← procedure label (from D_PROC pseudo-instruction)
    addr  loc:0,string:0        ← load address of string constant into local
    add   loc:8,const:10,const:2
    parm  loc:8                 ← push argument (right to left)
    parm  loc:0
    call  printf,2,loc:16       ← call, nargs, result location
    return  const:0
```

### println translation

K0's `println(expr)` is lowered to `printf`:

- `println(numericExpr)` — inject `%d\n` format string into `.string`, emit `addr` to load it, push value arg, push format arg, `call printf,2`
- `println("literal")` — string arg is already an address; push it directly, `call printf,1`

### Control flow

| K0 construct | TAC pattern |
|---|---|
| `if (c) T else E` | `bnif lab_else,cond` → T body → `goto lab_end` → `lab_else:` → E body → `lab_end:` |
| `while (c) B` | `lab_top:` → `bnif lab_end,cond` → B body → `goto lab_top` → `lab_end:` |
| `for (i in 0..10) B` | `asn iter,start` → `lab_top:` → B body → `goto lab_top` → `lab_end:` |
| `do B while (c)` | `lab_top:` → B body → cond code → `bif lab_top,cond` |

---

## Token Reference

### Keywords
```
FUN  VAL  VAR  IF  ELSE  WHILE  FOR  RETURN  BREAK  CONTINUE
WHEN  IN  DO  IMPORT  CONST  AS
```

### Literals
```
INTEGERLITERAL   LONGLITERAL   REALLITERAL   DOUBLELITERAL
BOOLEANLITERAL   CHARACTERLITERAL   STRINGLITERAL   NULLLITERAL
```

### Operators
```
=  +=  -=  *=  /=  %=        assignment
+  -  *  /  %                 arithmetic
++  --                         increment/decrement
==  !=  <  >  <=  >=           comparison
===  !==                       referential equality
&&  ||  !                      logical
?.  ?:  ?                      null-safety
..  ..<                        range / range-until
->  ::                         arrow / double-colon
```

---

## Known Limitations

| Feature | Status |
|---------|--------|
| `Array<Int>(5)` constructor call in expressions | Not supported — LALR(1) ambiguity with comparisons |
| Lambda / trailing lambdas `{ x -> ... }` | Not supported |
| String interpolation `"Hello $name"` | Treated as opaque `STRINGLITERAL` — `$name` not expanded at codegen |
| Named arguments `foo(x = 1)` | Removed — duplicates assignment expression |
| Classes / objects | Not in K0 spec |
| Unsigned integer literals | Lexer reports error |
| `.length` / member access result | Receiver evaluated; member result opaque |
| `arrayOf(...)` / collection literal codegen | Suppressed — no heap allocation in TAC |
| Scientific notation `1e10` | Lexer reports error |
| Nested `/* */` comments | Not supported |

---

## Example Output

### Intermediate code for the spec example

```kotlin
fun main() { println(10+2); }
```

```
.string 8
    %d\012\000
.code
main:
    addr    loc:0,string:0
    add     loc:8,const:10,const:2
    parm    loc:8
    parm    loc:0
    call    printf,2,loc:16
    return  const:0
```

### Semantic error examples

```bash
$ ./k0 err_immut.kt 2>&1
err_immut.kt
err_immut.kt:3: error: assignment to immutable variable 'x' (declared as val)

$ ./k0 err_null.kt 2>&1
err_null.kt
err_null.kt:2: error: type mismatch in declaration of 'x': expected int, got null
err_null.kt:2: error: null cannot be assigned to non-nullable 'x'

$ ./k0 err_arith.kt 2>&1
err_arith.kt
err_arith.kt:4: error: non-numeric left operand (bool) in arithmetic
```

---

## Running the Tests

```bash
# spec example
echo 'fun main() { println(10+2); }' > /tmp/foo.kt
./k0 /tmp/foo.kt && cat foo.ic

# full language coverage (38 functions)
./k0 test_cases/Test_full_v2.kt
cat Test_full_v2.ic

# generic type coverage
# ./k0 Test_generics.kt > out_generics.txt 2>&1

# valid programs — all should exit 0
./k0 test_cases/hello.kt;  echo "exit: $?"
./k0 test_cases/valid.kt;  echo "exit: $?"

# error cases — all should exit 3
./k0 test_cases/errors.kt 2>&1;        echo "exit: $?"
./k0 test_cases/err_immut.kt 2>&1;     echo "exit: $?"
./k0 test_cases/err_type_decl.kt 2>&1; echo "exit: $?"
./k0 test_cases/err_null.kt 2>&1;      echo "exit: $?"
./k0 test_cases/err_arith.kt 2>&1;     echo "exit: $?"
./k0 test_cases/err_logical.kt 2>&1;   echo "exit: $?"
./k0 test_cases/err_not.kt 2>&1;       echo "exit: $?"
./k0 test_cases/err_redecl.kt 2>&1;    echo "exit: $?"
```

---

*CSE 423 Compilers — New Mexico Institute of Mining and Technology*