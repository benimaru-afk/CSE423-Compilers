#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "symtab.h"

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
 * mksymtab() -- allocate and initialise a new symbol table
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTable mksymtab(int nbuckets)
{
    SymbolTable st = malloc(sizeof(struct sym_table));
    if (!st) { fprintf(stderr, "mksymtab: out of memory\n"); exit(1); }
    st->nBuckets = nbuckets;
    st->nEntries = 0;
    st->tbl = calloc(nbuckets, sizeof(struct sym_entry *));
    if (!st->tbl) { fprintf(stderr, "mksymtab: calloc failed\n"); exit(1); }
    return st;
}

/* ─────────────────────────────────────────────────────────────────────────
 * lookupsym() -- return entry or NULL
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTableEntry lookupsym(SymbolTable st, char *s)
{
    int h = hash(st, s);
    SymbolTableEntry e = st->tbl[h];
    while (e) {
        if (strcmp(e->s, s) == 0) return e;
        e = e->next;
    }
    return NULL;
}

/* ─────────────────────────────────────────────────────────────────────────
 * insertsym() -- insert if not present, return entry
 * ───────────────────────────────────────────────────────────────────────── */
SymbolTableEntry insertsym(SymbolTable st, char *s)
{
    SymbolTableEntry e = lookupsym(st, s);
    if (e) return e;

    e = malloc(sizeof(struct sym_entry));
    if (!e) { fprintf(stderr, "insertsym: out of memory\n"); exit(1); }
    e->s = strdup(s);
    if (!e->s) { fprintf(stderr, "insertsym: strdup failed\n"); exit(1); }

    int h = hash(st, s);
    e->next    = st->tbl[h];
    st->tbl[h] = e;
    st->nEntries++;
    return e;
}

/* ─────────────────────────────────────────────────────────────────────────
 * printsymtab() -- print all symbols, indented by 'indent' spaces
 * ───────────────────────────────────────────────────────────────────────── */
void printsymtab(SymbolTable st, int indent)
{
    if (!st) return;
    char pad[64] = "";
    int p = indent < 63 ? indent : 63;
    for (int i = 0; i < p; i++) pad[i] = ' ';
    pad[p] = '\0';

    printf("%s--- symbol table (%d entries, %d buckets) ---\n",
           pad, st->nEntries, st->nBuckets);
    for (int i = 0; i < st->nBuckets; i++) {
        SymbolTableEntry e = st->tbl[i];
        while (e) {
            printf("%s  [%3d]  %s\n", pad, i, e->s);
            e = e->next;
        }
    }
}