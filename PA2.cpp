/*********************************************************
Programming Assignment 2 CSCE 221-507
Ngo, Alexander    Nguyen, Quinn    Vallejo, Michael
alexanderkngo@tamu.edu    quinnminh_nguyen@tamu.edu    mvallejo@tamu.edu    
**********************************************************/


#include <sstream>
#include <iostream>
#include <fstream>
#include <string>

#include "sort.h"
#include "flight.h"
using namespace std;

std::vector<Flight> readFlights(std::string fileName);

int main()
{ 
  string input = "rand10000.csv";
  vector<Flight> test = readFlights(input);
  selection_sort(test, ByDestination);
  //selection_sort(test, ByDepartureTime);
  // bubble_sort(test, ByDepartureTime);
  // bubble_sort(test, ByDestination); 
  //insertion_sort(test, ByDepartureTime);
  // insertion_sort(test, ByDestination);
  if(test.size() == 10){
    for (int i = 0; i < test.size(); i++) {
      cout << test.at(i) <<endl;
    }
  }

  ofstream myfile;
  myfile.open("outputFile.csv");
  myfile << "Flight Number, Destination, Departure, Time, Gate Number\n";
  for (int i = 0; i < test.size(); i++) {
  	myfile << test.at(i).flightNum + ", " + test.at(i).destination + ", " + test.at(i).departureTime + ", " + test.at(i).gateNum + "\n";
  }
  myfile.close();




	/*
	first read flights in files using readFlights()
	descen10.csv	ascen10.csv     rand10.csv
	descen100.csv	ascen100.csv	rand100.csv
	descen1000.csv	ascen1000.csv	rand1000.csv
	descen10000.csv ascen10000.csv	rand10000.csv
	*/

	/*
	then use each of the sorting functions on each of the generated vectors
	*/

	/*
	then output each of the resultant sorted vectors
	format them so that they look like the table of the front of the 
        instructions

	Flight Number	Destination Departure   Time	        Gate Number
	AA223			LAS VEGAS	21:15			A3
	BA023			DALLAS		21:00			A3
	AA220			LONDON		20:30			B4
	VI303			MEXICO		19:00			A7
	BA087			LONDON		17:45			A7
	AA342			PARIS		16:00			A7
	VI309			PRAGUE		13:20			F2
	QU607			TORONTO		08:30			F2
	AA224			SYDNEY		08:20			A7
	AF342			WASHINGTON	07:45			A3
	*/

	/*
	then fill out the rest of the questions on the instructions 
	- the number of comparisons

	- to test your functions experimentally use difftime explained here 
        http://www.cplusplus.com/reference/ctime/time/
	*/

    return 0;
}



//read in the flights from the input file at fileName and store them in a vector
std::vector<Flight> readFlights(std::string fileName)
{
  ifstream inFS(fileName);
  string lines;
  string flightNumber, destination, departureTime, gateNumber;
  // inFS.open(fileName);
  std::vector<Flight> flights;

  //istream& getline(istream& inFS, string& str); // read the first line
  getline(inFS, lines);
  while (getline(inFS, lines)) {
  	stringstream linestream(lines);
  	getline(linestream, flightNumber, ',');
  	getline(linestream, destination, ',');
  	getline(linestream, departureTime, ',');
  	getline(linestream, gateNumber, ',');

  	Flight inputFlight(flightNumber, destination, departureTime, gateNumber);
  	flights.push_back(inputFlight);
  }

  return flights;
}

