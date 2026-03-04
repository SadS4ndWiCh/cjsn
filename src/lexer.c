#include "lexer.h"
#include "strview.h"
#include "token.h"

void _lexer_eat_whitespace(lexer_t *lex) {
    for (;;) {
        switch (lex->ch) {
            case ' ':
            case '\n':
            case '\t':
            case '\r':
            case '\v':
            case '\f':
                _lexer_read_char(lex);
                break;
            default:
                return;
        }
    }
}

void _lexer_read_char(lexer_t *lex) {
    if (lex->pos >= lex->len) {
        lex->ch = 0;
        return;
    }

    lex->ch = lex->src[lex->pos++];
}

char* _lexer_read_string(lexer_t *lex) {
    _lexer_read_char(lex);
    int start = lex->pos;

    while (lex->ch != '"') {
        _lexer_read_char(lex);
    }

    str_view_t view = { .src = lex->src + start - 1, .len = lex->pos - start };
    return str_view_get(view);
}

token_t lexer_next(lexer_t *lex) {
    _lexer_read_char(lex);
    _lexer_eat_whitespace(lex);

    switch (lex->ch) {
        case '{': return (token_t) { .kind = TK_OPBRACE, .literal = "{" };
        case '}': return (token_t) { .kind = TK_CLBRACE, .literal = "}" };
        case ':': return (token_t) { .kind = TK_COLON, .literal = ":" };
        case '"': {
            char* literal = _lexer_read_string(lex);
            return (token_t) { .kind = TK_STRING, .literal = literal };
        } break;
        case 0: return (token_t) { .kind = TK_EOF, .literal = "" };
        default: return (token_t) { .kind = TK_INVALID, .literal = "" };
    }
}
