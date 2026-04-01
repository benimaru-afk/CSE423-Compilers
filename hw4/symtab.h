#ifndef SYMTAB_H
#define SYMTAB_H

/* ─── Symbol table entry ─────────────────────────────────────────────────── */
typedef struct sym_entry {
    char   *name;              /* symbol string (owned copy)                  */
    char   *declared_type;     /* type name as string, e.g. "Int", "String"   */
    int     is_const;          /* 1 if declared with const val                */
    int     lineno;            /* line where declared (0 = predefined)        */
    char   *filename;          /* file where declared (NULL = predefined)     */
    struct sym_table *owner;   /* which symbol table owns this entry          */
    struct sym_entry *next;    /* next entry in same bucket (hash chaining)   */
} *SymbolTableEntry;

/* ─── Symbol table (hash table of linked lists) ──────────────────────────── */
typedef struct sym_table {
    char   *scope_name;        /* human-readable name, e.g. "global", "main" */
    int     nBuckets;          /* number of hash buckets                      */
    int     nEntries;          /* total symbols in this table                 */
    struct sym_table *parent;  /* enclosing scope for chained lookup          */
    struct sym_entry **tbl;    /* bucket array, length nBuckets               */
} *SymbolTable;

/* ─── Default bucket count ───────────────────────────────────────────────── */
#define SYM_NBUCKETS 64

/* ─── Public API ─────────────────────────────────────────────────────────── */
SymbolTable      mksymtab(int nbuckets, char *scope_name, SymbolTable parent);
SymbolTableEntry insertsym(SymbolTable st, char *name,
                           char *type, int is_const,
                           int lineno, char *filename);
SymbolTableEntry lookupsym(SymbolTable st, char *name);
SymbolTableEntry lookupsym_chain(SymbolTable st, char *name);
void             printsymtab(SymbolTable st);
void             printsymtab_all(SymbolTable global);
int              hash(SymbolTable st, char *s);

/* ─── Predefined symbol table (stdlib functions) ─────────────────────────── */
extern SymbolTable predefined_scope;
void               init_predefined(void);

/* ─── Error tracking ─────────────────────────────────────────────────────── */
extern int semantic_errors;

#endif /* SYMTAB_H */