# makefile

CC = gcc
CFLAGS = -O2 -std=c99 -pedantic -Wall
LIBS = 

all: dev

dev: $(LIBS)  main.c
	$(CC) $(CFLAGS) $(LIBS) main.c -o $@

clean:
	rm -f *~
	rm -f #*#
	rm -f *.o
	