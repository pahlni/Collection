CC=g++
CFLAGS=-std=c++11

all : PahlProject2

PahlProject2 : PahlProject2.o
	$(CC) $(CFLAGS) PahlProject2.o -o PahlProject2 

PahlProject2.o: PahlProject2.cpp
	$(CC) $(CFLAGS) -c PahlProject2.cpp
