CC     = gcc
CFLAGS = -Wall -g

OBJS = k0gram.tab.o lex.yy.o asi.o tree.o symtab.o symscan.o type.o typecheck.o tac.o codegen.o x86gen.o

k0: $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o k0

k0gram.tab.c k0gram.tab.h: k0gram.y
	bison -d k0gram.y

k0gram.tab.o: k0gram.tab.c k0gram.tab.h tree.h token.h prodrule.h symtab.h symscan.h type.h typecheck.h codegen.h tac.h
	$(CC) $(CFLAGS) -c k0gram.tab.c

lex.yy.c: k0lex.l k0gram.tab.h
	flex k0lex.l

lex.yy.o: lex.yy.c k0gram.tab.h tree.h token.h
	$(CC) $(CFLAGS) -c lex.yy.c

asi.o: asi.c k0gram.tab.h tree.h token.h
	$(CC) $(CFLAGS) -c asi.c

tree.o: tree.c tree.h token.h type.h
	$(CC) $(CFLAGS) -c tree.c

symtab.o: symtab.c symtab.h type.h tac.h
	$(CC) $(CFLAGS) -c symtab.c

symscan.o: symscan.c symscan.h tree.h token.h type.h symtab.h k0gram.tab.h
	$(CC) $(CFLAGS) -c symscan.c

type.o: type.c type.h symtab.h
	$(CC) $(CFLAGS) -c type.c

typecheck.o: typecheck.c typecheck.h tree.h token.h type.h symtab.h symscan.h k0gram.tab.h
	$(CC) $(CFLAGS) -c typecheck.c

tac.o: tac.c tac.h
	$(CC) $(CFLAGS) -c tac.c

codegen.o: codegen.c codegen.h tree.h token.h type.h symtab.h symscan.h tac.h k0gram.tab.h
	$(CC) $(CFLAGS) -c codegen.c

x86gen.o: x86gen.c x86gen.h codegen.h tac.h
	$(CC) $(CFLAGS) -c x86gen.c

clean:
	rm -f k0 $(OBJS) k0gram.tab.c k0gram.tab.h lex.yy.c *.ic *.s
