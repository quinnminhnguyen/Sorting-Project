/*********************************************************
Programming Assignment 2 CSCE 221-507
Ngo, Alexander    Nguyen, Quinn    Vallejo, Michael
alexanderkngo@tamu.edu    quinnminh_nguyen@tamu.edu    mvallejo@tamu.edu    
**********************************************************/

#include "flight.h"
#include <iostream>

Flight::Flight()
{
	flightNum = "";
	destination = "";
	departureTime = "";
	gateNum = "";
}

Flight::Flight(std::string fn, std::string dest, std::string dt, std::string gn)
{
	flightNum = fn;
	destination = dest;
	departureTime = dt;
	gateNum = gn;
}

Flight::~Flight()
{
	
}


bool compareToDestination(Flight f1, Flight f2)
{
	
	if (f1.destination > f2.destination) {
		return true;
	}
	else {
		return false;
	}
}
	 


bool compareToDepartureTime(Flight f1, Flight f2)
{
	
	if (f1.departureTime > f2.departureTime) {
		return true;
	}
	else {
		return false;
	}
}

std::ostream& operator<<(std::ostream& os,Flight& s){

	os << s.flightNum;
	for(int i = 0; i < (20-s.flightNum.size()); i++){
		os << " ";
	}

	os << s.destination;
	for(int i = 0; i < (20-s.destination.size()); i++){
		os << " ";
	}

	os << s.departureTime;
	for(int i = 0; i < (20-s.departureTime.size()); i++){
		os << " ";
	}

	os << s.gateNum;


	return os;

}