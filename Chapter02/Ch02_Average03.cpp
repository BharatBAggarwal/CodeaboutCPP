// Ch02_Average03.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>

// the main function
int main()
{
	short howMany,         // how many numbers to input
		numbersUsed = 0;   // numbers used in calculations

	double sum = 0.0,      // sum initialized to 0.0
		average = 0.0,     // average initialized to 0.0
		numbers[100];      // an array of dimension 100

	// input numbers into array
	std::cout << "How many numbers? ";
	std::cin >> howMany;

	std::cout << std::endl
		<< "To stop input at any time" << std::endl
		<< "enter a number > 30,000\n" << std::endl;

	for (int i = 0; i < howMany; ++i)
	{
		std::cout << "Input number #" << i + 1 << ": ";
		std::cin >> numbers[i];
		if (numbers[i] > 30000)
		{
			howMany = i; // numbers actually input in array
			break;       // end input loop
		}
	}

	// use array to calculate average
	for (int i = 0; i < howMany; ++i)
		{
		if (numbers[i] >= 10 && numbers[i] <= 20)
		{
			continue;        // go to top of loop
		}

		sum += numbers[i];  // calculate sum
		numbersUsed++;      // increment count of numbers
	}

	// calculate the average
	average = sum / numbersUsed;
	std::cout << std::endl << "Average of " << numbersUsed
		<< " numbers is " << average
		<< std::endl;

	return EXIT_SUCCESS;
}

