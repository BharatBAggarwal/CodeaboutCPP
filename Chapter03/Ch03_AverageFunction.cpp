// Ch03_Function.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include <memory>

// function to calculate an average
double average(short *numberOfElements,
	const std::unique_ptr<double[]> &data)
{
	double sum = 0.0;
	short numbersUsed = 0;     // numbers used in average

	for (int i = 0; i < *numberOfElements; ++i)
	{
		if (data[i] >= 10 && data[i] <= 20)
		{
			continue;      // go to top of loop
		}

		sum += data[i];   // calculate sum
		numbersUsed++;    // increment count of numbers used
	}

	*numberOfElements = numbersUsed;
	return (sum / numbersUsed);
}

// the main function
int main()
{
	short howMany;             // how many numbers
	double avg;                // average

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
			howMany = i;  // count of numbers in array
			break;        // end loop and calculate average
		}
	}

	// use the function to calculate average
	avg = average(&howMany, numbers);

	// After call to function, howMany contains numbers
	// used in average calculation
	std::cout << "Average of " << howMany
		<< " numbers is "
		<< avg
		<< std::endl;

	return EXIT_SUCCESS;
}
