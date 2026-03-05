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

char _lexer_seek_char(lexer_t *lex) {
    if (lex->pos >= lex->len) {
        return 0;
    }

    return lex->src[lex->pos];
}

char* _lexer_read_ident(lexer_t *lex) {
    int start = lex->pos;

    for (char ch = _lexer_seek_char(lex); IS_ALPHA(ch); ch = _lexer_seek_char(lex)) {
        _lexer_read_char(lex);
    }

    str_view_t view = { .src = lex->src + start - 1, .len = lex->pos - start + 1 };
    return str_view_get(view);
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

char* _lexer_read_number(lexer_t *lex) {
    int start = lex->pos;

    while (IS_DIGIT(_lexer_seek_char(lex))) {
        _lexer_read_char(lex);
    }

    str_view_t view = { .src = lex->src + start - 1, .len = lex->pos - start + 1 };
    return str_view_get(view);
}

token_t lexer_next(lexer_t *lex) {
    _lexer_read_char(lex);
    _lexer_eat_whitespace(lex);

    switch (lex->ch) {
        case '{': return (token_t) { .kind = TK_OPBRACE, .literal = "{" };
        case '}': return (token_t) { .kind = TK_CLBRACE, .literal = "}" };
        case '[': return (token_t) { .kind = TK_OPBRACKET, .literal = "[" };
        case ']': return (token_t) { .kind = TK_CLBRACKET, .literal = "]" };
        case ':': return (token_t) { .kind = TK_COLON, .literal = ":" };
        case ',': return (token_t) { .kind = TK_COLON, .literal = "," };
        case '"': {
            char* literal = _lexer_read_string(lex);
            return (token_t) { .kind = TK_STRING, .literal = literal };
        } break;
        case 0: return (token_t) { .kind = TK_EOF, .literal = "" };
        default:
            if (IS_ALPHA(lex->ch)) {
                char* literal = _lexer_read_ident(lex);
                token_kind_e tok = token_lookup_ident(literal);
                return (token_t) { .kind = tok, .literal = literal };
            }

            if (IS_DIGIT(lex->ch)) {
                char* literal = _lexer_read_number(lex);
                return (token_t) { .kind = TK_NUMBER, .literal = literal };
            }

            return (token_t) { .kind = TK_INVALID, .literal = "" };
    }
}
