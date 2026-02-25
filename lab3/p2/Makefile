# Makefile for K0 compiler (Kotlin subset)

CC      = gcc
CFLAGS  = -Wall -g

# ── Main parser ──────────────────────────────────────────────────────
k0: k0gram.tab.c lex.yy.c asi.c
	$(CC) $(CFLAGS) k0gram.tab.c lex.yy.c asi.c -o k0

# ── Debug token printer (no k0gram.tab.c — it has its own main) ──────
k0debug: lex.yy.c asi.c debug_main.c
	$(CC) $(CFLAGS) lex.yy.c asi.c debug_main.c -o k0debug

# ── Generated files ───────────────────────────────────────────────────
k0gram.tab.c k0gram.tab.h: k0gram.y
	bison -d k0gram.y

lex.yy.c: k0lex.l k0gram.tab.h
	flex k0lex.l

# ── Convenience targets ───────────────────────────────────────────────
all: k0 k0debug

clean:
	rm -f k0 k0debug k0gram.tab.c k0gram.tab.h lex.yy.c

rebuild: clean all

# ── Quick test targets ────────────────────────────────────────────────
test: k0
	./k0 hello.kt && echo "PASS: hello.kt" || echo "FAIL: hello.kt"

debug: k0debug
	./k0debug hello.kt

.PHONY: all clean rebuild test debug
