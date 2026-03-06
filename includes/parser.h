#ifndef __PARSER_H
#define __PARSER_H

#ifndef __LEXER_H
#include "lexer.h"
#endif

typedef struct {
    lexer_t* lex;

    token_t curr_token;
    token_t next_token;
} parser_t;

void parser_next(parser_t* parser);
void parser_parse(parser_t* parser);

#endif
