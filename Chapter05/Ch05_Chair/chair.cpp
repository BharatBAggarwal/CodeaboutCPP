// file: chair.cpp
// chair class implementation

#include "stdafx.h"
#include "chair.h"
#include <cstdlib>
#include <iostream>

Chair::Chair()
	  : Chair(colors::black, styles::basic)
{
	std::cout << "Default Constructor Chair object" << std::endl;
}

Chair::Chair(colors aColor, styles aStyle)
	  : acolor(aColor),       // set color to aColor
	    astyle(aStyle),       // set style to aStyle
	    broken(false),        // set broken to false
	    currentLoad(0.0),     // set currentLoad to 0.0
	    maxWeight(100.0),     // set weight capacity to 100.0
	    personWeight(-1.0),   // set person weight to -1.0
	    addedWeight(0.0)      // set added weight to 0.0
{
	std::cout << "Constructing a Chair object" << std::endl;
}

Chair::~Chair()
{
	std::cout << "Destroying a Chair object" << std::endl;
}

double Chair::sit(double weightOfPerson)
{
	if (broken)
	{
		std::cout << "Cannot sit on a broken chair!" << std::endl;
		return currentLoad;
	}

	if (!(personWeight < 0.0))
	{
		std::cout << "This chair is taken!" << std::endl;
		return currentLoad;
	}

	personWeight = weightOfPerson;
	return setCurrentWeight();
}

double Chair::addWeight(double aWeight)
{
	if (broken)
	{
		std::cout << "Cannot add weight to a broken chair!" << std::endl;
		return currentLoad;
	}

	addedWeight += aWeight;
	return setCurrentWeight();
}

double Chair::getOff()
{
	if (broken)
	{
		std::cout << "The chair is broken!" << std::endl;
		return currentLoad;
	}

	if (personWeight < 0.0)
	{
		std::cout << "No one is sitting on the chair!" << std::endl;
		return currentLoad;
	}

	personWeight = -1.0;
	return setCurrentWeight();
}

double Chair::removeWeight(double aWeight)
{
	if (broken)
	{
		std::cout << "The chair is broken!" << std::endl;
		return currentLoad;
	}

	addedWeight -= aWeight;
	if (addedWeight < 0.0)
	{
		addedWeight = 0.0;
	}

	return setCurrentWeight();
}

double Chair::currentWeight() const
{
	return currentLoad;
}

double Chair::setCurrentWeight()
{
	if (personWeight < 0.0)
	{
		currentLoad = addedWeight;
	}
	else
	{
		currentLoad = personWeight + addedWeight;
	}

	if (currentLoad > maxWeight)
	{
		broken = true;
		std::cout << std::endl
			<< "Weight " << currentLoad << " > "
			<< "Capacity " << maxWeight
			<< ". The chair broke!"
			<< std::endl;
	}
	return currentLoad;
}

bool Chair::isBroken() const
{
	return broken;
}

bool Chair::isSitting() const
{
	if (personWeight < 0.0)
		return false;
	else
		return true;
}

void Chair::clear()
{
	currentLoad = 0.0;
}

void Chair::refurbish()
{
	acolor = colors::black;
	astyle = styles::basic;
	broken = false;         // set broken to false
	currentLoad = 0.0;      // set currentLoad to 0.0
	maxWeight = 100.0;      // set weight capacity to 100.0
	personWeight = -1.0;    // set weight of last sit to -1.0
	addedWeight = 0.0;      // set weight of last sit to 0.0
}

Chair::colors Chair::color() const
{
	return acolor;
}

Chair& Chair::setColor(colors aColor)
{
	acolor = aColor;
	return *this;
}

Chair::styles Chair::style() const
{
	return astyle;
}

Chair& Chair::setStyle(styles aStyle)
{
	astyle = aStyle;
	return *this;
}

double Chair::capacity() const
{
	return maxWeight;
}

Chair& Chair::setCapacity(double limit)
{
	maxWeight = limit;
	return *this;
}
