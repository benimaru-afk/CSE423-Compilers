CC = gcc
CFLAGS = -Wall -g
LEX = flex

# Target executable
TARGET = a.out

# Object files
OBJS = main.o lex.yy.o

# Default target
all: $(TARGET)

# Link object files to create executable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $(TARGET) $(OBJS)

# Compile main.c to main.o
main.o: main.c lex.yy.h
	$(CC) $(CFLAGS) -c main.c

# Generate lex.yy.c from flex-wc.l and compile to lex.yy.o
lex.yy.o: lex.yy.c
	$(CC) $(CFLAGS) -c lex.yy.c

# Generate lex.yy.c from flex-wc.l
lex.yy.c: flex-wc.l
	$(LEX) flex-wc.l

# Clean up generated files
clean:
	rm -f $(TARGET) $(OBJS) lex.yy.c

# Phony targets
.PHONY: all clean