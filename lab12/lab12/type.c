#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "type.h"

/* ─── Static singleton instances for scalar types ────────────────────────── */
static struct typeinfo none_type    = { NONE_TYPE,   0 };
static struct typeinfo integer_type = { INT_TYPE,    0 };
static struct typeinfo float_type   = { FLOAT_TYPE,  0 };
static struct typeinfo bool_type    = { BOOL_TYPE,   0 };
static struct typeinfo char_type    = { CHAR_TYPE,   0 };
static struct typeinfo string_type  = { STRING_TYPE, 0 };
static struct typeinfo null_type    = { NULL_TYPE,   0 };
static struct typeinfo any_type     = { ANY_TYPE,    0 };

typeptr none_typeptr    = &none_type;
typeptr integer_typeptr = &integer_type;
typeptr float_typeptr   = &float_type;
typeptr bool_typeptr    = &bool_type;
typeptr char_typeptr    = &char_type;
typeptr string_typeptr  = &string_type;
typeptr null_typeptr    = &null_type;
typeptr any_typeptr     = &any_type;

/* ─── Type name strings (order matches base type codes - FIRST_TYPE) ─────── */
char *typenam[] = {
    "none",     /* NONE_TYPE    1000000 */
    "int",      /* INT_TYPE     1000001 */
    "float",    /* FLOAT_TYPE   1000002 */
    "bool",     /* BOOL_TYPE    1000003 */
    "char",     /* CHAR_TYPE    1000004 */
    "string",   /* STRING_TYPE  1000005 */
    "array",    /* ARRAY_TYPE   1000006 */
    "func",     /* FUNC_TYPE    1000007 */
    "class",    /* CLASS_TYPE   1000008 */
    "package",  /* PACKAGE_TYPE 1000009 */
    "any",      /* ANY_TYPE     1000010 */
    "null",     /* NULL_TYPE    1000011 */
};

/* ─────────────────────────────────────────────────────────────────────────
 * alctype() -- allocate (or return singleton for) a base type
 * ───────────────────────────────────────────────────────────────────────── */
typeptr alctype(int base)
{
    switch (base) {
        case NONE_TYPE:   return none_typeptr;
        case INT_TYPE:    return integer_typeptr;
        case FLOAT_TYPE:  return float_typeptr;
        case BOOL_TYPE:   return bool_typeptr;
        case CHAR_TYPE:   return char_typeptr;
        case STRING_TYPE: return string_typeptr;
        case NULL_TYPE:   return null_typeptr;
        case ANY_TYPE:    return any_typeptr;
        default: break;
    }
    typeptr rv = calloc(1, sizeof(struct typeinfo));
    if (!rv) { fprintf(stderr, "alctype: out of memory\n"); exit(1); }
    rv->basetype = base;
    rv->nullable = 0;
    return rv;
}

/* ─────────────────────────────────────────────────────────────────────────
 * alcfunctype() -- construct a function type
 * ───────────────────────────────────────────────────────────────────────── */
typeptr alcfunctype(struct sym_table *st, typeptr returntype)
{
    typeptr rv = alctype(FUNC_TYPE);
    rv->u.f.st         = st;
    rv->u.f.returntype = returntype;
    rv->u.f.nparams    = 0;
    rv->u.f.parameters = NULL;
    rv->u.f.defined    = 1;
    return rv;
}

/* ─────────────────────────────────────────────────────────────────────────
 * alcarraytype() -- construct an array type
 * ───────────────────────────────────────────────────────────────────────── */
typeptr alcarraytype(typeptr elemtype)
{
    typeptr rv = alctype(ARRAY_TYPE);
    rv->u.a.size     = -1;   /* unspecified */
    rv->u.a.elemtype = elemtype;
    return rv;
}

/* ─────────────────────────────────────────────────────────────────────────
 * typename_to_typeptr() -- map a K0 type name string to a typeptr.
 * This is the bridge between the string we extract from the syntax tree
 * (e.g. "Int", "Boolean", "Array") and the typeinfo struct system.
 * ───────────────────────────────────────────────────────────────────────── */
typeptr typename_to_typeptr(char *name)
{
    if (!name) return none_typeptr;

    /* Integer family */
    if (strcmp(name, "Int")   == 0) return integer_typeptr;
    if (strcmp(name, "Long")  == 0) return integer_typeptr;
    if (strcmp(name, "Short") == 0) return integer_typeptr;
    if (strcmp(name, "Byte")  == 0) return integer_typeptr;

    /* Float family */
    if (strcmp(name, "Double") == 0) return float_typeptr;
    if (strcmp(name, "Float")  == 0) return float_typeptr;

    /* Other scalars */
    if (strcmp(name, "Boolean") == 0) return bool_typeptr;
    if (strcmp(name, "Char")    == 0) return char_typeptr;
    if (strcmp(name, "String")  == 0) return string_typeptr;

    /* Null / Any */
    if (strcmp(name, "null") == 0) return null_typeptr;
    if (strcmp(name, "Any")  == 0) return any_typeptr;
    if (strcmp(name, "Unit") == 0) return none_typeptr;

    /* Array and collection types -- treat all as ARRAY_TYPE */
    if (strcmp(name, "Array") == 0 ||
        strcmp(name, "List")  == 0 ||
        strcmp(name, "Map")   == 0 ||
        strcmp(name, "Set")   == 0)
        return alcarraytype(any_typeptr);

    /* Function placeholder */
    if (strcmp(name, "Function") == 0) return alctype(FUNC_TYPE);

    /* Unknown -- return none */
    return none_typeptr;
}

/* ─────────────────────────────────────────────────────────────────────────
 * typename() -- return a human-readable string for a typeptr
 * ───────────────────────────────────────────────────────────────────────── */
char *typename(typeptr t)
{
    if (!t) return "(null)";
    if (t->basetype < FIRST_TYPE || t->basetype > LAST_TYPE)
        return "(bogus)";

    char *base = typenam[t->basetype - FIRST_TYPE];

    /* For array types, show the element type too */
    if (t->basetype == ARRAY_TYPE) {
        static char buf[128];
        char *elem = typename(t->u.a.elemtype);
        snprintf(buf, sizeof(buf), "array<%s>", elem ? elem : "?");
        return buf;
    }

    /* For function types, show return type */
    if (t->basetype == FUNC_TYPE) {
        static char buf[128];
        char *ret = typename(t->u.f.returntype);
        if (ret)
            snprintf(buf, sizeof(buf), "func->%s", ret);
        else
            snprintf(buf, sizeof(buf), "func");
        return buf;
    }

    return base;
}