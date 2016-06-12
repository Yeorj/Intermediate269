
CC=g++

CFLAG=-c -Wall -g

test: main.o
	$(CC) main.o -o test

main.o:
	$(CC) $(CFLAG) main.cpp

clean:
	rm *.o test
