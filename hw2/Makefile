CC=gcc
CFLAGS=-g -Wall
LEX=flex

k0lex: lex.yy.c main.c ytab.h token.h
	$(CC) $(CFLAGS) -o k0lex lex.yy.c main.c

lex.yy.c: k0lex.l ytab.h token.h
	$(LEX) -o lex.yy.c k0lex.l

clean:
	rm -f k0lex lex.yy.c *.o

test: k0lex
	./k0lex hello.kt
