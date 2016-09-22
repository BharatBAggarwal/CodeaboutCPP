// file: chair_impl.cpp
// Chair_Impl class implementation

#include "stdafx.h"
#include "chair_impl.h"
#include <cstdlib>
#include <iostream>

Chair_Impl::Chair_Impl()
	: Chair_Impl(ChairProperties::colors::black, ChairProperties::styles::basic)
{
}

Chair_Impl::Chair_Impl(ChairProperties::colors aColor, ChairProperties::styles aStyle)
	: acolor(aColor),     // set color to aColor
	astyle(aStyle),       // set style to aStyle
	broken(false),        // set broken to false
	currentLoad(0.0),     // set currentLoad to 0.0
	maxWeight(100.0),     // set weight capacity to 100.0
	personWeight(-1.0),   // set person weight to -1.0
	addedWeight(0.0)      // set added weight to 0.0
{
}

Chair_Impl::~Chair_Impl()
{
}

double Chair_Impl::sit(double weightOfPerson)
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

double Chair_Impl::addWeight(double aWeight)
{
	if (broken)
	{
		std::cout << "Cannot add weight to a broken chair!" << std::endl;
		return currentLoad;
	}

	addedWeight += aWeight;
	return setCurrentWeight();
}

double Chair_Impl::getOff()
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

double Chair_Impl::removeWeight(double aWeight)
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

double Chair_Impl::currentWeight() const
{
	return currentLoad;
}

double Chair_Impl::setCurrentWeight()
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

bool Chair_Impl::isBroken() const
{
	return broken;
}

bool Chair_Impl::isSitting() const
{
	if (personWeight < 0.0)
		return false;
	else
		return true;
}

void Chair_Impl::clear()
{
	currentLoad = 0.0;
}

void Chair_Impl::refurbish()
{
	acolor = ChairProperties::colors::black;
	astyle = ChairProperties::styles::basic;
	broken = false;         // set broken to false
	currentLoad = 0.0;      // set currentLoad to 0.0
	maxWeight = 100.0;      // set weight capacity to 100.0
	personWeight = -1.0;    // set weight of last sit to -1.0
	addedWeight = 0.0;      // set weight of last sit to 0.0
}

ChairProperties::colors Chair_Impl::color() const
{
	return acolor;
}

Chair_Impl& Chair_Impl::setColor(ChairProperties::colors aColor)
{
	acolor = aColor;
	return *this;
}

ChairProperties::styles Chair_Impl::style() const
{
	return astyle;
}

Chair_Impl& Chair_Impl::setStyle(ChairProperties::styles aStyle)
{
	astyle = aStyle;
	return *this;
}

double Chair_Impl::capacity() const
{
	return maxWeight;
}

Chair_Impl& Chair_Impl::setCapacity(double limit)
{
	maxWeight = limit;
	return *this;
}
