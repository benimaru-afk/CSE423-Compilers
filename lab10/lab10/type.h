#ifndef TYPE_H
#define TYPE_H

/* Forward declaration -- type.h and symtab.h include each other,
 * so we use a forward declaration to break the cycle.             */
struct sym_table;

/* ─── Parameter list node (for function types) ───────────────────────────── */
typedef struct param {
    char            *name;
    struct typeinfo *type;
    struct param    *next;
} *paramlist;

/* ─── Base type codes ────────────────────────────────────────────────────── */
#define FIRST_TYPE    1000000

#define NONE_TYPE     1000000   /* unknown / not yet assigned  */
#define INT_TYPE      1000001   /* Int, Long, Short, Byte      */
#define FLOAT_TYPE    1000002   /* Double, Float               */
#define BOOL_TYPE     1000003   /* Boolean                     */
#define CHAR_TYPE     1000004   /* Char                        */
#define STRING_TYPE   1000005   /* String                      */
#define ARRAY_TYPE    1000006   /* Array<T>                    */
#define FUNC_TYPE     1000007   /* function                    */
#define CLASS_TYPE    1000008   /* built-in class instances    */
#define PACKAGE_TYPE  1000009   /* import paths                */
#define ANY_TYPE      1000010   /* Any / unknown               */
#define NULL_TYPE     1000011   /* null literal                */

#define LAST_TYPE     1000011

/* ─── Type info struct ───────────────────────────────────────────────────── */
typedef struct typeinfo {
    int basetype;
    int nullable;    /* 1 if type was declared with '?' suffix */
    union {
        struct funcinfo {
            char            *name;
            int              defined;      /* 0=prototype, 1=defined */
            struct sym_table *st;          /* function's local scope */
            struct typeinfo  *returntype;
            int               nparams;
            struct param     *parameters;
        } f;
        struct arrayinfo {
            int              size;         /* -1 = unspecified       */
            struct typeinfo *elemtype;
        } a;
    } u;
} *typeptr;

/* ─── Singleton pointers for scalar types ────────────────────────────────── */
extern typeptr none_typeptr;
extern typeptr integer_typeptr;
extern typeptr float_typeptr;
extern typeptr bool_typeptr;
extern typeptr char_typeptr;
extern typeptr string_typeptr;
extern typeptr null_typeptr;
extern typeptr any_typeptr;

/* ─── Type name strings (indexed by basetype - FIRST_TYPE) ──────────────── */
extern char *typenam[];

/* ─── Constructors ───────────────────────────────────────────────────────── */
typeptr alctype(int basetype);
typeptr alcfunctype(struct sym_table *st, typeptr returntype);
typeptr alcarraytype(typeptr elemtype);
typeptr typename_to_typeptr(char *name);

/* ─── Utilities ──────────────────────────────────────────────────────────── */
char *typename(typeptr t);

#endif /* TYPE_H */