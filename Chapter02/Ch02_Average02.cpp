// Ch02_Average02.cpp
//

#include "stdafx.h"     // for visual studio
#include <cstdlib>
#include <iostream>

// the main function
int main()
{
	short howMany,           // how many numbers to input
		numbersUsed = 0;   // numbers used in calculations
	double sum = 0.0,       // sum initialized to 0.0
		number = 0.0,      // number initialized to 0.0
		average = 0.0;     // average initialized to 0.0

     // input count of numbers
	std::cout << "How many numbers? ";
	std::cin >> howMany;

	std::cout << std::endl
		<< "To stop input at any time" << std::endl
		<< "enter a number > 30,000\n" << std::endl;

     // input numbers
	for (int i = 0; i < howMany; ++i)
	{
		std::cout << "Input number #" << i + 1 << ": ";
		std::cin >> number;

		if (number > 30000)
		{
			break;       // end loop and calculate average
		}
		if (number >= 10 && number <= 20)
		{
			continue;     // go to top of loop
		}

		sum += number;   // calculate sum
		++numbersUsed;   // count of numbers added
	}

     // calculate average
	average = sum / numbersUsed;
	std::cout << std::endl << "Average of " << numbersUsed
		      << " numbers is " << average
		      << std::endl;

	return EXIT_SUCCESS;
}

