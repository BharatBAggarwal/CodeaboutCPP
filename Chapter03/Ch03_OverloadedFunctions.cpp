// Ch03_OverloadedFunctions.cpp
//

#include "stdafx.h" // for visual studio
#include <cstdlib>
#include <iostream>

// overloaded print functions
void print(int i)        // prints integers
{
	std::cout << "An int: " << i << std::endl;
}

void print(double  f)    // prints doubles
{
	std::cout << "A double: " << f << std::endl;
}

void print(char* c)      // prints characters
{
	std::cout << " Characters: " << c << std::endl;
}

// the main function
int main()
{
	print(10);            // calls print(int) to print 10
	print(10.0);          // calls print(double) to print 10.0
	print("ten");         // calls print(char*) to print "ten"

	return EXIT_SUCCESS;
}
