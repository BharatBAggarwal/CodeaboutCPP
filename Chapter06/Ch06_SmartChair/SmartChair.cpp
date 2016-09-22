// file: smartchair.cpp
// chair class definition

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "smartchair.h"

// initialize class variables outside the class
double SmartChair::cumulativeWeight = 0.0;
long   SmartChair::numberOfPersons = 0;
long   SmartChair::chairCounter = 0;

SmartChair::SmartChair()
	       : SmartChair(colors::black, styles::basic)
{
	std::cout << "Default Constructor: SmartChair" << std::endl;
}

SmartChair::SmartChair(colors aColor, styles aStyle)
	       : Chair(aColor, aStyle)
{
	++chairCounter;   // increment count of chairs
	std::cout << "Constructing a SmartChair object" << std::endl;
}

SmartChair::~SmartChair()
{
	--chairCounter;   // decrement count of chairs
	std::cout << "Destroying Chair object"
		<< "Active Chair objects: " << chairCounter
		<< std::endl;
}

double SmartChair::sit(double weightOfPerson)
{
	std::cout << std::endl
		      << "In sit() function in SmartChair"
			  << std::endl;

	cumulativeWeight += weightOfPerson;
	++numberOfPersons;

	return Chair::sit(weightOfPerson);
}

long SmartChair::chairsActive()
{
	return chairCounter;
}

double SmartChair::averageWeight()
{
	if (numberOfPersons == 0)
		return 0;
	else
		return cumulativeWeight / numberOfPersons;
}
