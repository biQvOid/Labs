CC = gcc
CFLAGS = -std=c99 -Wall -g
OBJ = main.o deque.o
PROG = program

build: main.o deque.o
	$(CC) $(CFLAGS) -o $(PROG) $(OBJ)

main.o: main.c
	$(CC) $(CFLAGS) -c main.c

deque.o: deque.c
	$(CC) $(CFLAGS) -c deque.c

clean:
	rm $(PROG) $(OBJ)
