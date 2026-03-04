CC := cc
CFLAGS := -Wall -Wextra
CINCLUDES := -I./includes

NAME := cjsn

SRCS := $(wildcard src/*.c)
DIST := bin

dist:
	mkdir -p $(DIST)

build: dist
	$(CC) $(CFLAGS) $(CINCLUDES) -o $(DIST)/$(NAME) $(SRCS)
