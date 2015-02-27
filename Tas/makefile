CC=gcc
CFLAGS= -W -Wall -ansi -pedantic -std=c99 -g
LDFLAGS=
EXEC=heap

all: $(EXEC)

heap: test_tas.o Heap.o
	$(CC) -o $@ $^ $(LDFLAGS)

test_tas.o: Heap.h

%.o: %.c
	$(CC) -o $@ -c $< $(CFLAGS)

.PHONY: clean mrproper

clean:
	rm -rf *.o

mrproper: clean
	rm -rf $(EXEC)