// Ch02_Containers.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <vector>
#include <map>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	std::vector <int> aVector1;        // an empty int vector
	std::vector <int> aVector2(50);    // an int vector with size 50.
	                                   // Elements not initialized.
	std::vector <int> aVector3(50, 5); // an int vector with size 50.
	                                   // All elements set to 5.

	// fill vector with values using [] operator. Bounds
	// checking is not performed
	for (int i = 0; i < aVector2.size(); ++i)
	{
		aVector2[i] = i;
	}

	// add new element at the end of vector
	aVector2.push_back(999);

	// remove element at the end of vector
	aVector2.pop_back();

	// replace current elements with 10 elements with value ‘x’
	aVector2.assign(10, 999);

	// element access
	aVector2.at(3);           // returns reference to fourth element.
	                          // bounds checking is performed.
	aVector2.front();         // returns the first element	
	aVector2.back();          // returns the last element	
	aVector2.data();          // returns a raw pointer to data array	

	// capacity related operations
	aVector2.max_size();      // maximum possible number of elements
	                          // that can be stored in the vector
	aVector2.capacity();      // number of elements that can be
	                          // stored in allocated memory
	aVector2.reserve(900);    // increase capacity to 900 elements
	aVector2.shrink_to_fit(); // set capacity equal to size.
	                          // frees unused memory.

	aVector2.size();          // number of elements in the vector
	aVector2.resize(100);     // set size to 100
	aVector2.clear();         // empty the vector. size() = 0
	aVector2.empty();         // returns true if vector is empty

	// create a map
	std::map<std::string, int> countries; // create empty map with a
	                                      // string key and int value

	// element access: Supports indexed access with no bounds
	// checking and provides a range checked at() function
	countries["USA"] = 1;      // USA country code 1
	countries["DEU"] = 49;     // Germany country code 49
	countries["CHN"] = 86;     // China country code 86
	countries["IND"] = 91;     // India country code 91

	countries.at("USA");       // country code = 1. bounds checked.
//	countries.at("JPN") = 81;  // Japan country code 81. error

	std::string keyStr("DEU");
	countries.find(keyStr);    // finds element with key = keyStr
	countries.erase(keyStr);   // erases element with key = keyStr
	countries.count(keyStr);   // returns count of elements with key = keyStr (0 or 1)

	countries.max_size();      // maximum possible size for a map
	countries.size();          // number of elements
	countries.clear();         // erase all elements
	countries.empty();         // true if the map has no elements

	return EXIT_SUCCESS;
}

