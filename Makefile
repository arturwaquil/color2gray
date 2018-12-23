#Makefile to compile color2gray

CC=g++
CFLAGS=-c -Wall -std=c++11
INCLUDE=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_imgcodecs

all: main.o color2gray.o
	$(CC) main.o color2gray.o $(INCLUDE) -o color2gray
	rm -rf *o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

color2gray.o: color2gray.cpp
	$(CC) $(CFLAGS) color2gray.cpp

clean:
	rm -rf *o color2gray
