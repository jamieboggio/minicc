#include <stdio.h>

#include "lexer.h"


int main(int argc, char const* argv[])
{
    (void)argc;
    (void)argv;

    if (printf("Hello from %s!", "ur mom") < 0) {
        return 1;
    }

    return 0;
}
