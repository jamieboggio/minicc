#pragma once

#include <stdbool.h>
#include <stddef.h>

typedef enum {
    TOKEN_EOF = 0,  // END OF FILE
    TOKEN_ERROR = 1,  // for "oops this shouldn't happen"
    TOKEN_LCUR = 2,  //   {
    TOKEN_RCUR = 3,  //   }
    TOKEN_LPAR = 4,  //   (
    TOKEN_RPAR = 5,  //   )
    TOKEN_SCOL = 6,  //   ;
    TOKEN_INTT = 7,  // KEYWORD: `int`
    TOKEN_RET = 8,  // KEYWORD: `return`
    TOKEN_IDEN = 9,  // identifier
    TOKEN_INTL = 10,  // int literal
    TOKEN_WS = 11,
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
