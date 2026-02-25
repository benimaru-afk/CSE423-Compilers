/*
 * tree.c - Syntax tree construction and traversal for K0 parser
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "tree.h"
#include "prodrule.h"
#include "k0gram.tab.h"

struct tree *parseroot = NULL;

/*
 * alloktree() - allocate an interior node with nkids children.
 * Children are passed as variadic struct tree* arguments.
 * Children that are NULL (epsilon productions) are skipped so
 * the printed tree stays clean.
 */
struct tree *alloktree(int prodrule, char *symbolname, int nkids, ...) {
    va_list ap;
    struct tree *t = malloc(sizeof(struct tree));
    if (!t) { fprintf(stderr, "alloktree: out of memory\n"); exit(3); }

    t->prodrule   = prodrule;
    t->symbolname = symbolname;
    t->nkids      = 0;
    t->leaf       = NULL;

    va_start(ap, nkids);
    for (int i = 0; i < nkids; i++) {
        struct tree *kid = va_arg(ap, struct tree *);
        if (kid != NULL) {
            if (t->nkids >= MAX_KIDS) {
                fprintf(stderr, "alloktree: too many kids\n");
                exit(3);
            }
            t->kids[t->nkids++] = kid;
        }
    }
    va_end(ap);

    return t;
}

/*
 * leafnode() - allocate a leaf node wrapping a token.
 */
struct tree *leafnode(struct token *tok) {
    struct tree *t = malloc(sizeof(struct tree));
    if (!t) { fprintf(stderr, "leafnode: out of memory\n"); exit(3); }

    t->prodrule   = 0;
    t->symbolname = NULL;
    t->nkids      = 0;
    t->leaf       = tok;

    return t;
}

/*
 * tokname() - return a human-readable string for a token code.
 */
static const char *tokname(int code) {
    switch (code) {
        case FUN:              return "FUN";
        case VAL:              return "VAL";
        case VAR:              return "VAR";
        case IF:               return "IF";
        case ELSE:             return "ELSE";
        case WHILE:            return "WHILE";
        case FOR:              return "FOR";
        case RETURN:           return "RETURN";
        case BREAK:            return "BREAK";
        case CONTINUE:         return "CONTINUE";
        case WHEN:             return "WHEN";
        case IN:               return "IN";
        case DO:               return "DO";
        case IMPORT:           return "IMPORT";
        case CONST:            return "CONST";
        case AS:               return "AS";
        case INTEGERLITERAL:   return "INTEGERLITERAL";
        case LONGLITERAL:      return "LONGLITERAL";
        case REALLITERAL:      return "REALLITERAL";
        case DOUBLELITERAL:    return "DOUBLELITERAL";
        case BOOLEANLITERAL:   return "BOOLEANLITERAL";
        case CHARACTERLITERAL: return "CHARACTERLITERAL";
        case STRINGLITERAL:    return "STRINGLITERAL";
        case NULLLITERAL:      return "NULLLITERAL";
        case IDENT:            return "IDENT";
        case ASSIGNMENT:       return "ASSIGNMENT";
        case ADD_ASSIGN:       return "ADD_ASSIGN";
        case SUB_ASSIGN:       return "SUB_ASSIGN";
        case MUL_ASSIGN:       return "MUL_ASSIGN";
        case DIV_ASSIGN:       return "DIV_ASSIGN";
        case MOD_ASSIGN:       return "MOD_ASSIGN";
        case ADD:              return "ADD";
        case SUB:              return "SUB";
        case MUL:              return "MUL";
        case DIV:              return "DIV";
        case MOD:              return "MOD";
        case INCR:             return "INCR";
        case DECR:             return "DECR";
        case EQ:               return "EQ";
        case NEQ:              return "NEQ";
        case GTE:              return "GTE";
        case LTE:              return "LTE";
        case LANGLE:           return "LANGLE";
        case RANGLE:           return "RANGLE";
        case REF_EQ:           return "REF_EQ";
        case REF_NEQ:          return "REF_NEQ";
        case AND:              return "AND";
        case OR:               return "OR";
        case NOT:              return "NOT";
        case SAFE_CALL:        return "SAFE_CALL";
        case ELVIS:            return "ELVIS";
        case QUEST:            return "QUEST";
        case RANGE:            return "RANGE";
        case RANGE_UNTIL:      return "RANGE_UNTIL";
        case LPAREN:           return "LPAREN";
        case RPAREN:           return "RPAREN";
        case LCURL:            return "LCURL";
        case RCURL:            return "RCURL";
        case LSQUARE:          return "LSQUARE";
        case RSQUARE:          return "RSQUARE";
        case COMMA:            return "COMMA";
        case DOT:              return "DOT";
        case COLON:            return "COLON";
        case SEMI:             return "SEMI";
        case ARROW:            return "ARROW";
        case DOUBLE_COLON:     return "DOUBLE_COLON";
        case NEWLINE:          return "NEWLINE";
        default:               return "UNKNOWN";
    }
}

/*
 * treeprint_r() - internal recursive helper that draws box-drawing lines.
 * Uses UTF-8 box-drawing characters: └─  ├─  │
 */
static void treeprint_r(struct tree *t, const char *prefix,
                         int is_last, int is_root) {
    if (t == NULL) return;

    /* UTF-8 box-drawing sequences */
    const char *LAST  = "\xe2\x94\x94\xe2\x94\x80 "; /* └─  */
    const char *MID   = "\xe2\x94\x9c\xe2\x94\x80 "; /* ├─  */
    const char *CONT  = "\xe2\x94\x82  ";             /* │   */
    const char *BLANK = "   ";                         /*     */

    /* Print this node */
    if (is_root) {
        /* Root: no connector */
        if (t->nkids == 0) {
            if (t->leaf)
                printf("%d:%s `%s`\n",
                       t->leaf->category,
                       tokname(t->leaf->category),
                       t->leaf->text ? t->leaf->text : "");
        } else {
            printf("%s\n", t->symbolname ? t->symbolname : "?");
        }
    } else {
        const char *conn = is_last ? LAST : MID;
        if (t->nkids == 0) {
            if (t->leaf)
                printf("%s%s%d:%s `%s`\n",
                       prefix, conn,
                       t->leaf->category,
                       tokname(t->leaf->category),
                       t->leaf->text ? t->leaf->text : "");
        } else {
            printf("%s%s%s\n",
                   prefix, conn,
                   t->symbolname ? t->symbolname : "?");
        }
    }

    /* Recurse into children */
    if (t->nkids > 0) {
        /* Find last non-NULL child */
        int last_nonnull = 0;
        for (int j = 0; j < t->nkids; j++)
            if (t->kids[j] != NULL) last_nonnull = j;

        /* Build prefix for children:
           if we are the last child (or root), no continuation bar;
           otherwise draw a bar so siblings below are connected. */
        char child_prefix[2048];
        if (is_root)
            snprintf(child_prefix, sizeof(child_prefix), "%s", prefix);
        else
            snprintf(child_prefix, sizeof(child_prefix), "%s%s",
                     prefix, is_last ? BLANK : CONT);

        for (int i = 0; i < t->nkids; i++) {
            if (t->kids[i] == NULL) continue;
            treeprint_r(t->kids[i], child_prefix, (i == last_nonnull), 0);
        }
    }
}

/*
 * treeprint() - print the syntax tree with box-drawing characters.
 * depth parameter kept for API compatibility but unused.
 */
void treeprint(struct tree *t, int depth) {
    (void)depth;
    treeprint_r(t, "", 0, 1);
}
/*
 * treefree() - recursively free the entire tree.
 */
void treefree(struct tree *t) {
    if (t == NULL) return;
    for (int i = 0; i < t->nkids; i++)
        treefree(t->kids[i]);
    /* Note: we do NOT free t->leaf->text here because tokens may be
       shared or point into yytext. Free token structs separately if needed. */
    free(t);
}