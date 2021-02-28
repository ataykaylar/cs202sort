all: sorting

sorting: main.o sorting.o 
	g++ main.o sorting.o -o sorting

main.o: main.cpp
	g++ -c main.cpp

sorting.o: sorting.cpp
	g++ -c sorting.cpp

clean: 
	rm -rf *o sorting