#include <stdio.h>

#include "lexer.h"

static const char* TOKEN_NAMES[] = {
    "EOF",
    "ERROR",
    "{",
    "}",
    "(",
    ")",
    ";",
    "int",
    "return",
    "<IDENTIFIER>",
    "<DIGIT>",
    "WS",
};

const char* token_to_str(token_t token)
{
    return TOKEN_NAMES[token];
}

int main(int argc, char const* argv[])
{
    if (argc != 2) {
        (void)fprintf(stderr, "Usage: %s <filepath>\n", argv[0]);
        return 1;
    }
    FILE* fp = fopen(argv[1], "r");
    if (fp == NULL) {
        (void)fprintf(stderr, "Error: file path must be valid\n");
        return 1;
    }

    tokenlist_t tokens = tokens_from_file(fp);
    for (size_t i = 0; i < tokens.size; i++) {
        printf("%s\n", token_to_str(tokens.token_array[i]));
    }
    (void)fclose(fp);
    return 0;
}
