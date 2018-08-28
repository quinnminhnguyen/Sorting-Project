/*********************************************************
Programming Assignment 2 CSCE 221-507
Ngo, Alexander    Nguyen, Quinn    Vallejo, Michael
alexanderkngo@tamu.edu    quinnminh_nguyen@tamu.edu    mvallejo@tamu.edu    
**********************************************************/

#include "sort.h"
#include <iostream>
using namespace std;

//use this to keep track of comparisons
int num_cmps = 0;

std::vector<Flight> selection_sort(std::vector<Flight> &flights,
				  SortOption sortOpt)
{    //pos_min is short for position of min
    int pos_min = 0;
    Flight temp_min_value;
    int num_cmps = 0;
    if (sortOpt == ByDestination) {
    	for (int i=0; i < flights.size(); i++) {
        	pos_min = i;//set pos_min to the current index of array
        
        	for (int j=i+1; j < flights.size(); j++) {
            	num_cmps++;
            	if (!compareToDestination(flights[j], flights[pos_min])) {
                	pos_min=j;
            	}
            }
            	//pos_min will keep track of the index that min is in, this is needed when a swap happens

        	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        		if (pos_min != i) {
            		temp_min_value = flights[i];
            		flights[i] = flights[pos_min];
            		flights[pos_min] = temp_min_value;
        		}	
    	}
    }
    if (sortOpt == ByDepartureTime) {
    	for (int i=0; i < flights.size(); i++) {
        	pos_min = i;//set pos_min to the current index of array
        
        	for (int j=i+1; j < flights.size(); j++) {
            	num_cmps++;
            	if (!compareToDepartureTime(flights[j], flights[pos_min])) {
                	pos_min=j;
            	}
            }
            	//pos_min will keep track of the index that min is in, this is needed when a swap happens

        	//if pos_min no longer equals i than a smaller value must have been found, so a swap must occur
        		if (pos_min != i) {
            		temp_min_value = flights[i];
            		flights[i] = flights[pos_min];
            		flights[pos_min] = temp_min_value;
        		}		
    	}
    }
  cout << "selection sort uses " << num_cmps <<" comparisions."<< endl;
  return flights;
}

std::vector<Flight> insertion_sort(std::vector<Flight> &flights,
				  SortOption sortOpt) {
    if(sortOpt == ByDepartureTime){
        for(int i = 1; i < flights.size(); i++){
            Flight temp = flights.at(i);
            int j = i - 1;
            while((j >= 0) && (++num_cmps, flights.at(j).departureTime >= temp.departureTime)){
                flights.at(j +1) = flights.at(j);
                --j;
            }
            flights.at(j+1) = temp;
        }
        cout << "insertion sort uses " << num_cmps <<" comparisions."<< endl;
    }
    else if(sortOpt == ByDestination){
        for(int i = 1; i < flights.size(); i++){
            Flight temp = flights.at(i);
            int j = i - 1;
            while((j >= 0) && (++num_cmps, flights.at(j).destination > temp.destination)){
                flights.at(j +1) = flights.at(j);
                --j;
            }
            flights.at(j+1) = temp;
        }
        cout << "insertion sort uses " << num_cmps <<" comparisions."<< endl;
    }
    
    num_cmps = 0;
  return flights;
}

std::vector<Flight> bubble_sort(std::vector<Flight> &flights,
			       SortOption sortOpt) {
    if (sortOpt == ByDestination) {
		for (int k = 1; k < flights.size(); k++){
			bool cont = false;
			for (int j = 0; j < flights.size() - k; j++) {
				num_cmps++;
                // flights[j].destination > flights[j + 1].destination
                if (sortOpt == ByDestination) {
				    if (compareToDestination(flights[j], flights[j + 1])) {
					   Flight tmp = flights.at(j + 1);
					   flights.at(j+ 1) = flights.at(j);
					   flights.at(j) = tmp;
					   cont = true;
				    }
			    }
            }       
            if (!cont) break;
		}
    }
	
	else if (sortOpt == ByDepartureTime) {
		for (int k = 1; k < flights.size(); k++){
            bool cont = false;
            for (int j = 0; j < flights.size() - k; j++) {
                num_cmps++;
                // flights[j].destination > flights[j + 1].destination
                if (compareToDepartureTime(flights[j], flights[j + 1])) {
                    Flight tmp = flights.at(j + 1);
                    flights.at(j+ 1) = flights.at(j);
                    flights.at(j) = tmp;
                    cont = true;
                }
                // cout << flights[j].destination << endl;
                // if (!cont) break; // stop sorting
            }
            // cout << "*****" << endl;
            if (!cont) break;
        }
	}
    cout << "Bubble sort uses "<< num_cmps <<" comparisons." << endl;
    num_cmps = 0;
	return flights;

}
