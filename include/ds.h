#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef enum {
    TOKEN_LCUR = 1,  //   {
    TOKEN_RCUR = 2,  //   }
    TOKEN_LPAR = 3,  //   (
    TOKEN_RPAR = 4,  //   )
    TOKEN_SCOL = 5,  //   ;
    TOKEN_INTT = 6,  // KEYWORD: `int`
    TOKEN_RET = 7,  // KEYWORD: `return`
    TOKEN_IDEN = 8,  // identifier
    TOKEN_INTL = 9,  // int literal
    TOKEN_EOF = -1,  // END OF FILE
    TOKEN_OTHER = 0,  // for "oops this shouldn't happen"
} token_t;

typedef struct tokenlist {
    token_t* token_array;
    size_t size;
    size_t capacity;
} tokenlist_t;

#define DEFAULT_SIZE 8UL

bool tokenlist_init(tokenlist_t* list, size_t init_cap);
bool append(tokenlist_t* list, token_t in_token);
bool pop(tokenlist_t* list, token_t* out_token);
void tokenlist_free(tokenlist_t* list);
