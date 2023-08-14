CC = gcc
CFLAGS = -Wall -Wextra -std=c99

all: memory_test

memory_test: memtest.c
	$(CC) $(CFLAGS) -o $@ $< -lm

clean:
	rm -f memory_test
