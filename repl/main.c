#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "token.h"

int main(void) {
    char* line = NULL;
    size_t len = 0;

    for (;;) {
        printf(">> ");
        if (getline(&line, &len, stdin) == -1) {
            perror("error: getline");
            return 1;
        }

        lexer_t lex = { .src = line, .len = strlen(line) };

        for (token_t tok = lexer_next(&lex); tok.kind != TK_EOF; tok = lexer_next(&lex)) {
            printf("tok.kind = %s, tok.literal = %s\n", token_str(tok.kind), tok.literal);

            if (tok.kind == TK_STRING) {
                free(tok.literal);
            }
        }
    }
}
