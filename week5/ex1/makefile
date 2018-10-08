# makefile

CC = gcc
CFLAGS = --pedantic -Wall -O2
LIBS = 

all: dev

dev: $(LIBS)  main.c
	$(CC) $(CFLAGS) $(LIBS) main.c -o $@

clean:
	rm -f *~
	rm -f #*#
	rm -f *.o
	