CC = gcc
CFLAGS = -Wall -Wextra -std=c99
TARGET = simplelang
SOURCES = main.c lexer.c parser.c ast.c codegen.c

$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) -o $(TARGET) $(SOURCES)

clean:
	rm -f $(TARGET)

.PHONY: clean