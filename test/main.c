#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "lexer.h"
#include "parser.h"

int main(void) {
    // char* src = "{\"hello\": \"world\", \"foo\": [\"bar\", true, false, 1353]}";
    char* src = "{\"hello\": {\"foo\": \"bar\"}}";

    lexer_t lex = { .src = src, .len = strlen(src) };
    parser_t parser = { .lex = &lex };

    parser_next(&parser);
    parser_next(&parser);

    parser_parse(&parser);

    // for (token_t tok = lexer_next(&lex); tok.kind != TK_EOF; tok = lexer_next(&lex)) {
    //     printf("kind = %s, literal = %s\n", token_str(tok.kind), tok.literal);

    //     if (tok.kind == TK_STRING) {
    //         free(tok.literal);
    //     }
    // }
}
