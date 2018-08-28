/*********************************************************
Programming Assignment 2 CSCE 221-507
Ngo, Alexander    Nguyen, Quinn    Vallejo, Michael
alexanderkngo@tamu.edu    quinnminh_nguyen@tamu.edu    mvallejo@tamu.edu    
**********************************************************/

#pragma once
#include <vector>
#include <string>

#include "flight.h"

enum SortOption {
  ByDestination,
  ByDepartureTime
};

//implement each of these functions for their respective sort
std::vector<Flight> selection_sort(std::vector<Flight> &flights,
				  SortOption sortOpt);

std::vector<Flight> insertion_sort(std::vector<Flight> &flights,
				  SortOption sortOpt);

std::vector<Flight> bubble_sort(std::vector<Flight> &flights,
			       SortOption sortOpt);
