#ifndef __LEXER_H
#define __LEXER_H

#ifndef __TOKEN_H
#include "token.h"
#endif

typedef struct {
    char* src;
    int len;
    int pos;
    char ch;
} lexer_t;

void _lexer_eat_whitespace(lexer_t* lex);
void _lexer_read_char(lexer_t* lex);
char* _lexer_read_string(lexer_t* lex);
token_t lexer_next(lexer_t* lex);

#endif
