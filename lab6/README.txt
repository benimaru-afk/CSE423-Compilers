CSE 423 -- Lab 6: Hashing and Symbol Tables
Wrap-Up Report
Ben Mannal and Suhtiha Kantareddy
================================================================================

QUESTIONS: How do you tell you have your symbols in place?
           You should print those tables out. How hard will that be?
================================================================================

Printing the symbol tables turned out to be straightforward once the traversal
was working correctly. The printsymtab() function iterates over every bucket in
the hash table and walks each bucket's linked list, printing the symbol string
and its bucket index. Adding indentation as a parameter made nested scopes
visually distinct from the global scope. The whole function is about 15 lines.

The harder part was not the printing -- it was getting the symbols into the
tables in the first place. The main challenges encountered were:

  1. Tree traversal order: printsyms() and buildsyms() were originally called
     after treefree(), so the traversal was walking already-freed memory,
     causing a segfault. Moving both calls before treefree() fixed this.

  2. Prodrule values: the switch(t->prodrule) approach produced garbage values
     at runtime despite the struct layout being correct. Switching to
     strcmp(t->symbolname, "function_declaration") etc. was more robust since
     symbolname is a string literal set directly in every alloktree() call.

  3. NULL kids: alloktree() skips NULL children (epsilon productions) and
     compacts the kids[] array, so nkids reflects only non-NULL children.
     Fixed indices (e.g. "body is always kids[4]") broke when optional nodes
     were absent. Finding the body by scanning kids[] for a symbolname of
     "block" or "function_body" made it layout-independent.


VERIFICATION -- PART 1 (printsyms)
-----------------------------------

Running printsyms() on Test_full_v2.kt produced:

  Total identifier occurrences : 324
  Unique identifiers            : 102

This was verified by piping the Part 1 output through wc and sort | uniq | wc.
The count covers every IDENT token in the file -- function names, parameter
names, variable names, type names, and call targets like println.


VERIFICATION -- PART 2 (buildsyms / symbol tables)
----------------------------------------------------

The symbol tables were verified by inspection of the printed output.

Global scope:
  38 entries -- one per top-level function declaration in Test_full_v2.kt.
  All 38 function names (main, add, sumArray, makeArray, ..., arrayInit)
  appear exactly once. No duplicates, no missing entries.

Selected local scopes (parameters + var/val declarations):

  Function       Entries  Contents
  -------------- -------  -----------------------------------------------
  add                  2  x, y  (both parameters)
  sumArray             3  arr (param), total, x  (loop var + local val)
  arithmetic           7  a, b (params), sum, diff, prod, quot, rem
  comparisons         10  a, b (params), eq, neq, lt, gt, lte, gte, ref, nref
  literals             9  a, b, c, d, e, f, g, h, i  (9 val declarations)
  logical              5  a, b (params), andExpr, orExpr, notExpr
  nestedCalls          0  correct -- no declarations, just a return expression
  returnVoid           0  correct -- empty body, no declarations

Each count was cross-checked against the source in Test_full_v2.kt and matched.


HOW HARD WAS IT?
----------------

Printing the tables: easy. One function, 15 lines, works on the first try.

Getting the symbols in: moderately hard. Three bugs had to be resolved:

  - The treefree-before-traversal ordering bug (runtime, found via segfault)
  - The prodrule garbage values (runtime, found via debug prints)
  - The NULL-kid index assumption (logic bug, found by comparing expected vs
    actual entry counts)

Total implementation across symtab.h, symtab.c, symscan.h, and symscan.c
is approximately 225 lines of C. The data structure itself (hash table of
linked lists) was simple to implement. The complexity was entirely in
navigating the parse tree correctly.


FILES ADDED/MODIFIED
--------------------

  symtab.h    -- SymbolTableEntry and SymbolTable struct definitions,
                 SYM_NBUCKETS constant, public API declarations

  symtab.c    -- hash(), mksymtab(), lookupsym(), insertsym(), printsymtab()

  symscan.h   -- declares printsyms() and buildsyms()

  symscan.c   -- printsyms() tree walk (Part 1)
                 buildsyms() / scan_node() / insert_params() (Part 2)

  k0gram.y    -- added #include "symscan.h" and two calls in main():
                   printsyms(parseroot)
                   buildsyms(parseroot)
                 both placed before treefree(parseroot)

  Makefile    -- added symtab.o and symscan.o to OBJS, added build rules
                 with correct header dependencies for each

================================================================================

Team Members:        Contribution:
Benjamin Mannal     |     2
Suhitha Kantareddy  |     2