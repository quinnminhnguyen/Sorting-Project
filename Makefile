all: PA2.o sort.o flight.o
	c++ -std=c++11 -g PA2.o sort.o flight.o -o main
PA2.o: PA2.cpp flight.cpp flight.h sort.cpp sort.h
	c++ -std=c++11 -c -g PA2.cpp
sort.o: sort.cpp sort.h flight.cpp flight.h
	c++ -std=c++11 -c -g sort.cpp
flight.o: flight.cpp flight.h
	c++ -std=c++11 -c -g flight.cpp
clean:
	rm *.o main
