CC      = gcc
CFLAGS  = -Wall -g

all: k0

k0gram.tab.c k0gram.tab.h: k0gram.y
	bison -d k0gram.y

lex.yy.c: k0lex.l k0gram.tab.h
	flex k0lex.l

k0: k0gram.tab.c lex.yy.c asi.c tree.c
	$(CC) $(CFLAGS) k0gram.tab.c lex.yy.c asi.c tree.c -o k0

debug: lex.yy.c asi.c debug_main.c
	$(CC) $(CFLAGS) lex.yy.c asi.c debug_main.c -o k0debug
	./k0debug hello.kt

clean:
	rm -f k0 k0debug k0gram.tab.c k0gram.tab.h lex.yy.c

.PHONY: all debug clean