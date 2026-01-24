#include <stdio.h>
#include <stdlib.h>
#include "ytab.h"
#include "token.h"

extern int yylex();
extern struct token yytoken;
extern FILE *yyin;
extern char *current_filename;

struct tokenlist* add_token(struct tokenlist *list, struct token *t);
void print_tokens(struct tokenlist *list);

int main(int argc, char **argv) {
    struct tokenlist *tokens = NULL;
    int token_code;
    
    if (argc > 1) {
        current_filename = argv[1];  // Set filename FIRST
        yyin = fopen(argv[1], "r");
        if (!yyin) {
            fprintf(stderr, "Error: cannot open file %s\n", argv[1]);
            return 1;
        }
    } else {
        current_filename = "stdin";  // Default if no file given
    }
    
    while ((token_code = yylex()) > 0) {
        /* Create a copy of the current token */
        struct token *t = malloc(sizeof(struct token));
        *t = yytoken;
        
        /* Add to linked list */
        tokens = add_token(tokens, t);
    }
    
    print_tokens(tokens);
    
    return 0;
}

struct tokenlist* add_token(struct tokenlist *list, struct token *t) {
    struct tokenlist *new_node = malloc(sizeof(struct tokenlist));
    new_node->t = t;
    new_node->next = NULL;
    
    if (list == NULL) {
        return new_node;
    }
    
    struct tokenlist *current = list;
    while (current->next != NULL) {
        current = current->next;
    }
    current->next = new_node;
    
    return list;
}

void print_tokens(struct tokenlist *list) {
    printf("%-12s%-20s%-12s%-20s%s\n", 
           "Category", "Text", "Lineno", "Filename", "Ival/Sval");
    printf("--------------------------------------------------------------------------------\n");
    
    struct tokenlist *current = list;
    while (current != NULL) {
        struct token *t = current->t;
        
        // Print category, text, lineno, filename with fixed widths
        printf("%-12d%-20s%-12d%-20s", 
               t->category, t->text, t->lineno, t->filename);
        
        // Print value based on token type
        if (t->category == INTEGERLITERAL) {
            printf("%d", t->ival);
        } else if (t->category == REALLITERAL) {
            printf("%f", t->dval);
        } else if (t->category == STRINGLITERAL && t->sval) {
            printf("%s", t->sval);
        }
        printf("\n");
        
        current = current->next;
    }
}