#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"
#include "type.h"

int semantic_errors  = 0;
SymbolTable predefined_scope = NULL;

int hash(SymbolTable st, char *s)
{
    register int h = 0;
    register char c;
    while ((c = *s++)) { h += c & 0377; h *= 37; }
    if (h < 0) h = -h;
    return h % st->nBuckets;
}

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

SymbolTableEntry lookupsym_chain(SymbolTable st, char *name)
{
    while (st) {
        SymbolTableEntry e = lookupsym(st, name);
        if (e) return e;
        st = st->parent;
    }
    return NULL;
}

SymbolTableEntry insertsym(SymbolTable st, char *name,
                           typeptr type, int is_const, int is_mutable,
                           int lineno, char *filename)
{
    SymbolTableEntry existing = lookupsym(st, name);
    if (existing) {
        fprintf(stderr,
                "%s:%d: error: redeclaration of '%s' "
                "(previously declared at %s:%d)\n",
                filename ? filename : "<unknown>", lineno, name,
                existing->filename ? existing->filename : "<unknown>",
                existing->lineno);
        semantic_errors++;
        return NULL;
    }

    SymbolTableEntry e = malloc(sizeof(struct sym_entry));
    if (!e) { fprintf(stderr, "insertsym: out of memory\n"); exit(1); }

    e->name       = strdup(name);
    e->type       = type;
    e->is_const   = is_const;
    e->is_mutable = is_mutable;
    e->lineno     = lineno;
    e->filename   = filename ? strdup(filename) : NULL;
    e->owner      = st;

    int h       = hash(st, name);
    e->next     = st->tbl[h];
    st->tbl[h]  = e;
    st->nEntries++;
    return e;
}

void printsymtab(SymbolTable st)
{
    if (!st) return;
    printf("--- symbol table for: %s ---\n",
           st->scope_name ? st->scope_name : "?");
    for (int i = 0; i < st->nBuckets; i++) {
        SymbolTableEntry e = st->tbl[i];
        while (e) {
            char *tname = e->type ? typename(e->type) : "unknown";
            char *mut   = e->is_const   ? " [const]"   :
                          e->is_mutable ? " [var]"      : " [val]";
            printf("    %-20s : %s%s%s\n",
                   e->name, tname,
                   (e->type && e->type->nullable) ? "?" : "",
                   mut);
            e = e->next;
        }
    }
    printf("---\n");
}

void init_predefined(void)
{
    predefined_scope = mksymtab(SYM_NBUCKETS, "predefined", NULL);

    static const char *fns[] = {
        "print", "println", "readln",
        "abs", "max", "min", "pow", "cos", "sin", "tan",
        NULL
    };
    typeptr ft = alctype(FUNC_TYPE);
    for (int i = 0; fns[i]; i++)
        insertsym(predefined_scope, (char*)fns[i], ft, 0, 0, 0, NULL);

    static const char *types[] = {
        "Int", "Long", "Double", "Float", "Short", "Byte",
        "Boolean", "String", "Char", "Any", "Unit", "Nothing",
        "Array", "List", "Map", "Set",
        NULL
    };
    typeptr ct = alctype(CLASS_TYPE);
    for (int i = 0; types[i]; i++)
        insertsym(predefined_scope, (char*)types[i], ct, 0, 0, 0, NULL);
}