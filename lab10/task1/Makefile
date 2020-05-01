CC=gcc
LD=gcc
CFLAGS=-ggdb -Wall -pedantic -std=c11 -O3
LDFLAGS=

EX2_PROG=matrix_mul_ijk
2ND_PROG=matrix_mul_jki
3RD_PROG=matrix_mul_ikj

PROGS=$(EX2_PROG) $(2ND_PROG) $(3RD_PROG)

all: $(PROGS)

ex2:
		$(CC) -o $(EX2_PROG) $(CFLAGS) $(EX2_PROG).c
			./$(EX2_PROG)


clean:
		-rm -rf core *.o *~ "#"*"#" Makefile.bak $(PROGS) *.dSYM

