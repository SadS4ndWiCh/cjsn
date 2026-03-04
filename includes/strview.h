#ifndef __STRVIEW_H
#define __STRVIEW_H

#include <stdlib.h>
#include <string.h>

typedef struct {
    char* src;
    int len;
} str_view_t;

char* str_view_get(str_view_t view) {
    char* buf = (char*) malloc(sizeof(char) * view.len + 1);
    memset(buf, 0, view.len + 1);
    strncpy(buf, view.src, view.len);
    return buf;
}

#endif
