# makefile

CC = gcc
CFLAGS = -fopenmp 

all: dev

dev: main.c
	$(CC) $(CFLAGS) main.c -o $@

clean:
	rm -f *~
	rm -f #*#
	rm -f *.o
