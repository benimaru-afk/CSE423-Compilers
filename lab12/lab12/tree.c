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
    t->stab       = NULL;
    t->type       = NULL;
    t->place      = ADDR_NONE;
    t->first      = ADDR_NONE;
    t->follow     = ADDR_NONE;
    t->onTrue     = ADDR_NONE;
    t->onFalse    = ADDR_NONE;
    t->has_first  = 0;
    t->has_follow = 0;
    t->has_onTrue = 0;
    t->has_onFalse = 0;

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
    t->stab       = NULL;
    t->type       = NULL;
    t->place      = ADDR_NONE;
    t->first      = ADDR_NONE;
    t->follow     = ADDR_NONE;
    t->onTrue     = ADDR_NONE;
    t->onFalse    = ADDR_NONE;
    t->has_first  = 0;
    t->has_follow = 0;
    t->has_onTrue = 0;
    t->has_onFalse = 0;

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

void printnode(struct tree *t) {
    if (t == NULL) {
        printf("NULL node\n");
        return;
    }

    if (t->nkids == 0) {
        if (t->leaf != NULL) {
            printf("LEAF: category=%d text=%s line=%d file=%s\n",
                   t->leaf->category,
                   t->leaf->text ? t->leaf->text : "(null)",
                   t->leaf->lineno,
                   t->leaf->filename ? t->leaf->filename : "(null)");
        } else {
            printf("LEAF: epsilon/null leaf\n");
        }
    } else {
        printf("NODE: rule=%d symbol=%s nkids=%d\n",
               t->prodrule,
               t->symbolname ? t->symbolname : "(null)",
               t->nkids);
    }
}
/* =========================================================
 * Lab 12: DOT output with semantic and codegen annotations
 * ========================================================= */
#include "type.h"

static void dot_escape(FILE *out, const char *s)
{
    if (!s) return;
    for (; *s; s++) {
        switch (*s) {
            case '\\': fputs("\\\\", out); break;
            case '"':  fputs("\\\"", out); break;
            case '\n': fputs("\\n", out); break;
            case '\r': break;
            case '\t': fputs("    ", out); break;
            default:   fputc(*s, out); break;
        }
    }
}

static const char *dot_addr_region(int r)
{
    switch (r) {
        case R_GLOBAL: return "global";
        case R_LOCAL:  return "loc";
        case R_CLASS:  return "class";
        case R_LABEL:  return "lab";
        case R_CONST:  return "const";
        case R_NAME:   return "name";
        case R_STRING: return "string";
        case R_NONE:   return "none";
        default:       return "?";
    }
}

static int dot_addr_active(struct addr a)
{
    return a.region != R_NONE && a.region != 0;
}

static void dot_print_addr(FILE *out, const char *label, struct addr a)
{
    if (!dot_addr_active(a)) return;
    fprintf(out, "\\n%s=", label);
    if (a.region == R_NAME)
        fprintf(out, "%s:%s", dot_addr_region(a.region), a.u.name ? a.u.name : "?");
    else
        fprintf(out, "%s:%d", dot_addr_region(a.region), a.u.offset);
}

static void dot_print_type(FILE *out, typeptr t)
{
    if (!t || t->basetype == NONE_TYPE) return;
    fprintf(out, "\\ntype=");
    dot_escape(out, typename(t));
    if (t->nullable) fprintf(out, "?");
}

static int dot_tree_nodes(FILE *out, struct tree *t, int *nextid)
{
    if (!t) return -1;
    int my = (*nextid)++;

    if (t->leaf) {
        fprintf(out, "  n%d [shape=box, style=\"rounded,filled\", fillcolor=\"#efe6ff\", color=\"#7b2cbf\", label=\"", my);
        fprintf(out, "%d:", t->leaf->category);
        dot_escape(out, tokname(t->leaf->category));
        fprintf(out, "\\n` ");
        dot_escape(out, t->leaf->text ? t->leaf->text : "");
        fprintf(out, " `");
    } else {
        fprintf(out, "  n%d [shape=ellipse, style=filled, fillcolor=\"#f6f0ff\", color=\"#5a189a\", label=\"", my);
        dot_escape(out, t->symbolname ? t->symbolname : "?");
    }

    dot_print_type(out, t->type);
    dot_print_addr(out, "place", t->place);
    if (t->has_first)  dot_print_addr(out, "first",  t->first);
    if (t->has_follow) dot_print_addr(out, "follow", t->follow);
    if (t->has_onTrue) dot_print_addr(out, "true",   t->onTrue);
    if (t->has_onFalse)dot_print_addr(out, "false",  t->onFalse);
    fprintf(out, "\"];\n");

    for (int i = 0; i < t->nkids; i++) {
        int kid = dot_tree_nodes(out, t->kids[i], nextid);
        if (kid >= 0) fprintf(out, "  n%d -> n%d;\n", my, kid);
    }
    return my;
}

static void dot_print_instr_label(FILE *out, struct instr *in)
{
    if (!in) return;
    if (in->opcode >= D_GLOB && in->opcode <= D_PROT)
        dot_escape(out, pseudoname(in->opcode));
    else
        dot_escape(out, opcodename(in->opcode));

    dot_print_addr(out, "dest", in->dest);
    dot_print_addr(out, "src1", in->src1);
    dot_print_addr(out, "src2", in->src2);
}

void treedot(struct tree *t, struct instr *code, const char *filename)
{
    FILE *out = fopen(filename, "w");
    if (!out) {
        fprintf(stderr, "treedot: could not open %s for writing\n", filename);
        return;
    }

    fprintf(out, "digraph K0Tree {\n");
    fprintf(out, "  graph [rankdir=TB, labelloc=t, label=\"Lab 12 DOT Syntax Tree with type/place/TAC info\"];\n");
    fprintf(out, "  node [fontname=Courier];\n");
    fprintf(out, "  edge [color=\"#555555\"];\n\n");

    int nextid = 0;
    dot_tree_nodes(out, t, &nextid);

    if (code) {
        fprintf(out, "\n  subgraph cluster_tac {\n");
        fprintf(out, "    label=\"Intermediate code linked list\";\n");
        fprintf(out, "    color=\"#9d4edd\"; style=\"dashed\";\n");
        int i = 0;
        for (struct instr *p = code; p; p = p->next, i++) {
            fprintf(out, "    tac%d [shape=note, style=filled, fillcolor=\"#e0f7fa\", color=\"#0077b6\", label=\"", i);
            dot_print_instr_label(out, p);
            fprintf(out, "\"];\n");
            if (i > 0) fprintf(out, "    tac%d -> tac%d [style=dashed, color=\"#0077b6\"];\n", i-1, i);
        }
        fprintf(out, "  }\n");
    }

    fprintf(out, "}\n");
    fclose(out);
}
