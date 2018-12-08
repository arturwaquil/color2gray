#Makefile to compile c2g-cli

CC=g++
CFLAGS=-c -Wall -std=c++11
INCLUDE=-lopencv_core -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_imgcodecs

all: c2g

c2g: main.o color2gray.o
	$(CC) main.o color2gray.o $(INCLUDE) -o c2g-cli
	$rm -rf *o

main.o: main.cpp
	$(CC) $(CFLAGS) main.cpp

color2gray.o: color2gray.cpp
	$(CC) $(CFLAGS) color2gray.cpp

clean:
	rm -rf *o c2g
