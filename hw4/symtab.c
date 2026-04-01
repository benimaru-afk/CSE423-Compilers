#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

/* Global error counter -- incremented on every semantic error */
int semantic_errors = 0;

/* Predefined (stdlib) scope */
SymbolTable predefined_scope = NULL;

/* ─────────────────────────────────────────────────────────────────────────
 * hash()
 * ───────────────────────────────────────────────────────────────────────── */
int hash(SymbolTable st, char *s)
{
    register int h = 0;
    register char c;
    while ((c = *s++)) {
        h += c & 0377;
        h *= 37;
    }
    if (h < 0) h = -h;
    return h % st->nBuckets;
}

/* ─────────────────────────────────────────────────────────────────────────
 * mksymtab()
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTable mksymtab(int nbuckets, char *scope_name, SymbolTable parent)
{
    SymbolTable st = malloc(sizeof(struct sym_table));
    if (!st) { fprintf(stderr, "mksymtab: out of memory\n"); exit(1); }
    st->scope_name = scope_name ? strdup(scope_name) : NULL;
    st->nBuckets   = nbuckets;
    st->nEntries   = 0;
    st->parent     = parent;
    st->tbl        = calloc(nbuckets, sizeof(struct sym_entry *));
    if (!st->tbl)  { fprintf(stderr, "mksymtab: calloc failed\n"); exit(1); }
    return st;
}

/* ─────────────────────────────────────────────────────────────────────────
 * lookupsym() -- search one table only
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTableEntry lookupsym(SymbolTable st, char *name)
{
    if (!st) return NULL;
    int h = hash(st, name);
    SymbolTableEntry e = st->tbl[h];
    while (e) {
        if (strcmp(e->name, name) == 0) return e;
        e = e->next;
    }
    return NULL;
}

/* ─────────────────────────────────────────────────────────────────────────
 * lookupsym_chain() -- search this table then all parent scopes
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTableEntry lookupsym_chain(SymbolTable st, char *name)
{
    while (st) {
        SymbolTableEntry e = lookupsym(st, name);
        if (e) return e;
        st = st->parent;
    }
    return NULL;
}

/* ─────────────────────────────────────────────────────────────────────────
 * insertsym() -- insert; report redeclaration error if already present
 *   Returns the new entry, or NULL on redeclaration.
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTableEntry insertsym(SymbolTable st, char *name,
                           char *type, int is_const,
                           int lineno, char *filename)
{
    /* Check for redeclaration in THIS scope (not parent scopes) */
    SymbolTableEntry existing = lookupsym(st, name);
    if (existing) {
        fprintf(stderr,
                "%s:%d: error: redeclaration of '%s' "
                "(previously declared at %s:%d)\n",
                filename ? filename : "<unknown>", lineno,
                name,
                existing->filename ? existing->filename : "<unknown>",
                existing->lineno);
        semantic_errors++;
        return NULL;
    }

    SymbolTableEntry e = malloc(sizeof(struct sym_entry));
    if (!e) { fprintf(stderr, "insertsym: out of memory\n"); exit(1); }

    e->name          = strdup(name);
    e->declared_type = type ? strdup(type) : NULL;
    e->is_const      = is_const;
    e->lineno        = lineno;
    e->filename      = filename ? strdup(filename) : NULL;
    e->owner         = st;

    int h       = hash(st, name);
    e->next     = st->tbl[h];
    st->tbl[h]  = e;
    st->nEntries++;
    return e;
}

/* ─────────────────────────────────────────────────────────────────────────
 * printsymtab() -- print one table in the required format
 * ───────────────────────────────────────────────────────────────────────── */
void printsymtab(SymbolTable st)
{
    if (!st) return;
    printf("--- symbol table for: %s ---\n",
           st->scope_name ? st->scope_name : "?");
    for (int i = 0; i < st->nBuckets; i++) {
        SymbolTableEntry e = st->tbl[i];
        while (e) {
            if (e->declared_type)
                printf("    %s : %s%s\n",
                       e->name, e->declared_type,
                       e->is_const ? "  [const]" : "");
            else
                printf("    %s%s\n",
                       e->name,
                       e->is_const ? "  [const]" : "");
            e = e->next;
        }
    }
    printf("---\n");
}

/* ─────────────────────────────────────────────────────────────────────────
 * init_predefined() -- populate the predefined (stdlib) symbol table
 * ───────────────────────────────────────────────────────────────────────── */
void init_predefined(void)
{
    predefined_scope = mksymtab(SYM_NBUCKETS, "predefined", NULL);

    /* Standard library functions from the K0 spec */
    static const char *fns[] = {
        "print", "println", "readln",
        "abs", "max", "min", "pow", "cos", "sin", "tan",
        NULL
    };
    for (int i = 0; fns[i]; i++)
        insertsym(predefined_scope, (char*)fns[i], "Function", 0, 0, NULL);

    /* Predefined type names -- used in as-casts and type checks */
    static const char *types[] = {
        "Int", "Long", "Double", "Float", "Short", "Byte",
        "Boolean", "String", "Char", "Any", "Unit", "Nothing",
        "Array", "List", "Map", "Set",
        NULL
    };
    for (int i = 0; types[i]; i++)
        insertsym(predefined_scope, (char*)types[i], "Type", 0, 0, NULL);
}