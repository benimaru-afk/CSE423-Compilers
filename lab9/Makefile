CC     = gcc
CFLAGS = -Wall -g

lab9: lab9main.o tac.o
	$(CC) $(CFLAGS) lab9main.o tac.o -o lab9

lab9main.o: lab9main.c tac.h
	$(CC) $(CFLAGS) -c lab9main.c

tac.o: tac.c tac.h
	$(CC) $(CFLAGS) -c tac.c

clean:
	rm -f lab9 lab9main.o tac.o
