// Ch02_Average04.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"   // for visual studio
#include <cstdlib>
#include <iostream>
#include <memory>

// the main function
int main()
{
	short howMany,           // how many numbers
		numbersUsed = 0;     // numbers used in average
	double sum = 0.0,        // sum initialized to 0.0
		average = 0.0;       // average initialized to 0.0

	// input numbers into array
	std::cout << "How many numbers? ";
	std::cin >> howMany;

	// use smart pointer for array storage
	std::unique_ptr<double[]> numbers(new double[howMany]);
	if (numbers == nullptr)
	{
		std::cout << "Error allocating memory for array"
			<< std::endl;
		return EXIT_FAILURE;           // end program
	}

	std::cout << std::endl
		<< "To stop input at any time" << std::endl
		<< "enter a number > 30,000\n" << std::endl;

	for (int i = 0; i < howMany; ++i)  // input numbers
	{
		std::cout << "Input number #" << i + 1 << ": ";
		std::cin >> numbers[i];

		if (numbers[i] > 30000)
		{
			howMany = i;  // numbers actually input in array 
			break;        // end input loop
		}
	}

	// use numbers array to calculate average
	for (int i = 0; i < howMany; i++)
	{
		if (numbers[i] >= 10 && numbers[i] <= 20)
		{
			continue;      // go to top of loop
		}

		sum += numbers[i]; // calculate sum
		numbersUsed++;    // increment count of numbers used
	}

	// calculate average
	average = sum / numbersUsed;
	std::cout << std::endl << "Average of " << numbersUsed
		<< " numbers is " << average
		<< std::endl;

	return EXIT_SUCCESS;
}

