#ifndef SYMTAB_H
#define SYMTAB_H

/* ─── Symbol table entry ─────────────────────────────────────────────────── */
typedef struct sym_entry {
    char *s;                   /* the symbol string */
    /* more attributes (type, offset, etc.) go here for code generation */
    struct sym_entry *next;    /* next entry in the same bucket */
} *SymbolTableEntry;

/* ─── Symbol table (hash table of linked lists) ──────────────────────────── */
typedef struct sym_table {
    int nBuckets;              /* number of hash buckets */
    int nEntries;              /* total symbols in this table */
    /* struct sym_table *parent; */   /* enclosing scope -- uncomment when needed */
    struct sym_entry **tbl;    /* array of bucket heads, length nBuckets */
} *SymbolTable;

/* ─── Default bucket count ───────────────────────────────────────────────── */
#define SYM_NBUCKETS 64

/* ─── Public API ─────────────────────────────────────────────────────────── */
SymbolTable      mksymtab(int nbuckets);
SymbolTableEntry insertsym(SymbolTable st, char *s);
SymbolTableEntry lookupsym(SymbolTable st, char *s);
void             printsymtab(SymbolTable st, int indent);
int              hash(SymbolTable st, char *s);

#endif /* SYMTAB_H */