// SpeedFunction02.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>

// function prototype
extern int speed(double aDistance, double aTime,
	             double *aSpeedPtr);

// function definition
int speed(double aDistance, double aTime,
	      double *aSpeedPtr)          // for output
{
	if (aTime > 0.0)
	{
		*aSpeedPtr = aDistance / aTime;
		return EXIT_SUCCESS;
	}
	else
	{
		*aSpeedPtr = 0.0;
		return EXIT_FAILURE;
	}
}

// the main function
int main(void)
{
	double distance,
		time,
		aSpeed;

	// input distance and time
	std::cout << "Distance? ";
	std::cin  >> distance;
	std::cout << "Time? ";
	std::cin  >> time;

	if (speed(distance, time, &aSpeed) == EXIT_SUCCESS)
	{
		std::cout << "Speed = " << aSpeed << std::endl;
		return EXIT_SUCCESS;
	}
	else
	{
		std::cout << "Error in calculation" << std::endl;
		return EXIT_FAILURE;
	}

}

