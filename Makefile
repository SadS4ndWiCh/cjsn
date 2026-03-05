CC := cc
CFLAGS := -Wall -Wextra
CINCLUDES := -I./includes

NAME := cjsn

SRCS := $(wildcard src/*.c)
DIST := bin

dist:
	mkdir -p $(DIST)

test: dist
	$(CC) $(CFLAGS) $(CINCLUDES) -o $(DIST)/$(NAME) $(SRCS) test/main.c

repl: dist
	$(CC) $(CFLAGS) $(CINCLUDES) -o $(DIST)/repl $(SRCS) repl/main.c

build: test repl
