CC=gcc
CFLAGS=-I. -g -Wall -Wextra -Werror -pedantic -std=c99

DEPS = hw7_fns.h

OBJ = hw7_fns.o

%.o: %.c $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

all: hw7p1 hw7p2 hw7p3 hw7p4 hw7p5 hw7p6

hw7p1: hw7p1.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

hw7p2: hw7p2.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

hw7p3: hw7p3.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

hw7p4: hw7p4.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

hw7p5: hw7p5.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

hw7p6: hw7p6.c $(OBJ)
	$(CC) -o $@ $^ $(CFLAGS)

.PHONY: clean

clean:
	rm -f $(OBJ) hw7p1 hw7p2 hw7p3 hw7p4 hw7p5 hw7p6 valgrind-out.txt a.out
