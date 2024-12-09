TARGET = conway
CC = gcc
CFLAGS = -Wall
SOURCES = main.c
HEADER = automatas.h

clean: all
	rm *.o $(TARGET)
run: all
	clear
	./$(TARGET)
all: main
	gcc -o $(TARGET) main.o
main: main.c $(HEADER)
	gcc -c $(CFLAGS) $(SOURCES) -o main.o
