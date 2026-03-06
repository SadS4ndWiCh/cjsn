#include "parser.h"
#include "lexer.h"
#include "token.h"
#include <assert.h>

void parser_next(parser_t* parser) {
    parser->curr_token = parser->next_token;
    parser->next_token = lexer_next(parser->lex);
}

void __parser_parse_object(parser_t* parser) {
    assert(parser->curr_token.kind == TK_OPBRACE);

    parser_next(parser);
    if (parser->curr_token.kind == TK_CLBRACE) {
        return;
    }

    for (;;) {
        assert(parser->curr_token.kind == TK_STRING);
        parser_next(parser);
        assert(parser->curr_token.kind == TK_COLON);
        parser_next(parser);

        parser_parse(parser);

        if (parser->curr_token.kind == TK_COMMA) {
            parser_next(parser);
            continue;
        }

        assert(parser->curr_token.kind == TK_CLBRACE);
        parser_next(parser);
        break;
    }
}

void parser_parse(parser_t *parser) {
    switch (parser->curr_token.kind) {
        case TK_OPBRACE:
            __parser_parse_object(parser);
            break;
        default:
            parser_next(parser);
            break;
    }
}
