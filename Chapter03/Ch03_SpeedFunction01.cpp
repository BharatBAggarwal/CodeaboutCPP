// Ch03_SpeedFunction01.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>

// function prototype
extern double speed(double aDistance, double aTime);

// function definition
double speed(double aDistance, double aTime)
{
	double aSpeed;
	if (aTime > 0.0)
	{
		aSpeed = aDistance / aTime;
	}
	else
	{
		std::cout << "Value of time must be greater than 0"
				  << std::endl;
		aSpeed = 0.0;
	}

	return aSpeed;
}

// the main function
int main(void)
{
	double distance,
		time;

	// input distance and time
	std::cout << "Distance? ";
	std::cin  >> distance;
	std::cout << "Time? ";
	std::cin  >> time;

	std::cout << "Speed = " << speed(distance, time)
			  << std::endl;

	return EXIT_SUCCESS;
}
