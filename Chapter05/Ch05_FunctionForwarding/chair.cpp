// file: chair_impl.cpp
// Chair_Impl class implementation

#include "stdafx.h"
#include "chair_impl.h"
#include "chair.h"
#include <cstdlib>
#include <iostream>

Chair::Chair()
	: Chair(ChairProperties::colors::black, ChairProperties::styles::basic)
{
}

Chair::Chair(ChairProperties::colors aColor, ChairProperties::styles aStyle)
{
	chairImpl = std::unique_ptr<Chair_Impl>(new Chair_Impl(aColor, aStyle));
}

Chair::Chair(Chair& aChair)
{
	chairImpl = std::unique_ptr<Chair_Impl>(new Chair_Impl());
	chairImpl->setCapacity(aChair.capacity());
	chairImpl->setColor(aChair.color());
	chairImpl->setStyle(aChair.style());
}

Chair::~Chair()
{
}

double Chair::sit(double weightOfPerson)
{
	return chairImpl->sit(weightOfPerson);
}

double Chair::addWeight(double aWeight)
{
	return chairImpl->addWeight(aWeight);
}

double Chair::getOff()
{
	return chairImpl->getOff();
}

double Chair::removeWeight(double aWeight)
{
	return chairImpl->removeWeight(aWeight);
}

double Chair::currentWeight() const
{
	return chairImpl->currentWeight();
}

bool Chair::isBroken() const
{
	return chairImpl->isBroken();
}

bool Chair::isSitting() const
{
	return chairImpl->isSitting();
}

void Chair::clear()
{
	chairImpl->clear();
}

void Chair::refurbish()
{
	chairImpl->refurbish();
}

ChairProperties::colors Chair::color() const
{
	return 	chairImpl->color();
}

Chair& Chair::setColor(ChairProperties::colors aColor)
{
	chairImpl->setColor(aColor);
	return *this;
}

ChairProperties::styles Chair::style() const
{
	return chairImpl->style();
}

Chair& Chair::setStyle(ChairProperties::styles aStyle)
{
	chairImpl->setStyle(aStyle);
	return *this;
}

double Chair::capacity() const
{
	return chairImpl->capacity();
}

Chair& Chair::setCapacity(double limit)
{
	chairImpl->setCapacity(limit);
	return *this;
}
