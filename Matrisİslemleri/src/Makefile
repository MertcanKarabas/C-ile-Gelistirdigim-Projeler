CC=gcc
CFLAGS=-c -Wall
all:makePROJECT1 clean run

makeBP3: projemain.o matrisoperations.o
	$(CC) projemain.o matrisoperations.o -o PROJECT1

main.o:main.c
	$(CC) $(CFLAGS) main.c

matrisoperations.o: matrisoperations.c matrisoperations.h
	$(CC) $(CFLAGS) matrisoperations.c
	
clean:
	del *.o
