#include "token.h"
#include <string.h>

const char* token_str(token_kind_e tok) {
    switch (tok) {
        case TK_EOF:       return "TK_EOF";
        case TK_INVALID:   return "TK_INVALID";
        case TK_OPBRACE:   return "TK_OPBRACE";
        case TK_CLBRACE:   return "TK_CLBRACE";
        case TK_OPBRACKET: return "TK_OPBRACKET";
        case TK_CLBRACKET: return "TK_CLBRACKET";
        case TK_COMMA:     return "TK_COMMA";
        case TK_COLON:     return "TK_COLON";
        case TK_STRING:    return "TK_STRING";
        case TK_NUMBER:    return "TK_NUMBER";
        case TK_TRUE:      return "TK_TRUE";
        case TK_FALSE:     return "TK_FALSE";
        default:           return "UNKNOWN";
    }
}

token_kind_e token_lookup_ident(char* ident) {
    if (strcmp(ident, "true") == 0) return TK_TRUE;
    if (strcmp(ident, "false") == 0) return TK_FALSE;
    return TK_INVALID;
}
