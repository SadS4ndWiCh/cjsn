#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"

int main(void) {
    char* src = "{\"hello\": \"world\", \"foo\": [\"bar\", true, false, 1353]}";

    lexer_t lex = { .src = src, .len = strlen(src) };

    for (token_t tok = lexer_next(&lex); tok.kind != TK_EOF; tok = lexer_next(&lex)) {
        printf("kind = %s, literal = %s\n", token_str(tok.kind), tok.literal);

        if (tok.kind == TK_STRING) {
            free(tok.literal);
        }
    }

    printf("Hello World!\n");
}
