#ifndef __TOKEN_H
#define __TOKEN_H

typedef enum {
    TK_EOF,
    TK_INVALID,

    TK_OPBRACE,
    TK_CLBRACE,
    TK_OPBRACKET,
    TK_CLBRACKET,

    TK_COMMA,
    TK_COLON,

    TK_STRING,
    TK_NUMBER,
    TK_TRUE,
    TK_FALSE,

    TK_LENGTH
} token_kind_e;

typedef struct {
    token_kind_e kind;
    char* literal;
} token_t;

const char* token_str(token_kind_e tok);
token_kind_e token_lookup_ident(char* ident);

#endif
