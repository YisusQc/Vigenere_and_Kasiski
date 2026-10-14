all: main

main.o: main.cpp
	g++ -c main.cpp

vignere.o: vignere.cpp vignere.hpp
	g++ -c vignere.cpp

kasiski.o: kasiski.cpp kasiski.hpp
	g++ -c kasiski.cpp

utils.o: utils.cpp utils.hpp
	g++ -c utils.cpp

main: main.o vignere.o kasiski.o utils.o
	g++ -o main main.o vignere.o kasiski.o utils.o

clean:
	rm -f main *.o

