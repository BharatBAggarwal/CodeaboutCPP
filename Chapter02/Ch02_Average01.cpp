// Ch02_Average01.cpp
//

#include "stdafx.h"      // for visual studio
#include <cstdlib>
#include <iostream>

// the main function
int main()
{
	long howMany;         // how many numbers to input
	double sum = 0.0,     // sum initialized to 0.0
		number = 0.0,    // number initialized to 0.0
		average = 0.0;   // average initialized to 0.0

	// input the count of numbers
	std::cout << "How many numbers? ";
	std::cin >> howMany;

	// calculate the sum of numbers
	for (int i = 0; i < howMany; ++i)
	{
		std::cout << "Input number #" << i + 1 << ": ";
		std::cin >> number;

		sum += number;
	}

	// calculate the average
	average = sum / howMany;
	std::cout << std::endl << "Average is " << average
		<< std::endl;

	return EXIT_SUCCESS;
}

