// Ch02_AverageVector.cpp
//

#include "stdafx.h"      // for visual studio
#include <cstdlib>
#include <iostream>
#include <vector>

// the main function
int main()
{
	short howMany,         // how many numbers to input
		  numbersUsed = 0, // numbers used in calculations
	      temp = 0;        // numbers used in calculations

	double sum = 0.0,      // sum initialized to 0.0
		average = 0.0;     // average initialized to 0.0

	std::vector<int> numbers;   // an empty vector

	// input numbers into array
	std::cout << "How many numbers? ";
	std::cin >> howMany;

	std::cout << std::endl
		<< "To stop input at any time" << std::endl
		<< "enter a number > 30,000\n" << std::endl;

	for (int i = 0; i < howMany; ++i)
	{
		std::cout << "Input number #" << i + 1 << ": ";
		std::cin >> temp;
		if (temp > 30000)
		{
			break;        // end input loop
		}
		numbers.push_back(temp);
	}

	// use array to sum numbers
	for (int i = 0; i < numbers.size(); ++i)
	{
		if (numbers[i] >= 10 && numbers[i] <= 20)
		{
			continue;        // go to top of loop
		}

		sum += numbers[i];  // calculate sum
		numbersUsed++;      // increment count of numbers
	}

	// calculate average
	average = sum / numbersUsed;
	std::cout << std::endl << "Average of " << numbersUsed
		<< " numbers is " << average
		<< std::endl;

	return EXIT_SUCCESS;
}
