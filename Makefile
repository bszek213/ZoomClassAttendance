all: mainClass

mainClass: mainClass.o
	g++ -Wall -std=c++17 -o mainClass mainClass.o

mainClass.o: mainClass.cpp stringContainer.h
	g++ -Wall -std=c++17 -c mainClass.cpp

clean:
	rm -rf *o mainClass

