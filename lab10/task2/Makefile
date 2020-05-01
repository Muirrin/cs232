CC=gcc
CFLAGS=-g -O3 -Wall -std=c11

asciimation: snode.c snode.h slist.h slist.c frame.c frame.h asciimation.c asciimation.h main.c
	$(CC) $(CFLAGS) snode.c slist.c frame.c asciimation.c main.c -o asciimation

clean:
	rm -f *.o asciimation a.out
