
CC=g++

CFLAGS = -Wall -g -std=c++11

test: main.o mirror.o
	$(CC) $(CFLAGS) main.o mirror.o -o test

main.o: mirror.h main.cpp
	$(CC) $(CFLAGS) -c main.cpp

mirror.o: mirror.h mirror.cpp
	$(CC) $(CFLAGS) -c mirror.cpp

clean:
	rm *.o test
