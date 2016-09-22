// file: recliningchair.cpp
// RecliningChair class implementation

#include "stdafx.h"
#include "recliningchair.h"
#include "chair_impl.h"
#include "recliner.h"

#include <cstdlib>
#include <iostream>

RecliningChair::RecliningChair()
	: RecliningChair(ChairProperties::colors::black, ChairProperties::styles::basic)
{
}

RecliningChair::RecliningChair(ChairProperties::colors aColor, ChairProperties::styles aStyle)
{
	// assign concrete objects to interface pointers
	chairImpl = std::unique_ptr<IChair>(new Chair_Impl(aColor, aStyle));
	aRecliner = std::unique_ptr<IRecliner>(new Recliner());
}

RecliningChair::RecliningChair(RecliningChair& aChair)
{
	// chair copy
	chairImpl = std::unique_ptr<IChair>(new Chair_Impl());
	chairImpl->setColor(aChair.color());
	chairImpl->setStyle(aChair.style());

	// recliner copy
	aRecliner = std::unique_ptr<IRecliner>(new Recliner());
	aRecliner->setAngle(aChair.recline());
}

RecliningChair::~RecliningChair()
{
}

int RecliningChair::recline()
{
	return aRecliner->angle();
}

void RecliningChair::setRecline(int anAngle)
{
	return aRecliner->setAngle(anAngle);
}


double RecliningChair::sit(double weightOfPerson)
{
	return chairImpl->sit(weightOfPerson);
}

double RecliningChair::addWeight(double aWeight)
{
	return chairImpl->addWeight(aWeight);
}

double RecliningChair::getOff()
{
	return chairImpl->getOff();
}

double RecliningChair::removeWeight(double aWeight)
{
	return chairImpl->removeWeight(aWeight);
}

double RecliningChair::currentWeight() const
{
	return chairImpl->currentWeight();
}

bool RecliningChair::isBroken() const
{
	return chairImpl->isBroken();
}

bool RecliningChair::isSitting() const
{
	return chairImpl->isSitting();
}

void RecliningChair::clear()
{
	chairImpl->clear();
}

void RecliningChair::refurbish()
{
	aRecliner->reset();
	chairImpl->refurbish();
}

ChairProperties::colors RecliningChair::color() const
{
	return 	chairImpl->color();
}

IChair& RecliningChair::setColor(ChairProperties::colors aColor)
{
	chairImpl->setColor(aColor);
	return *this;
}

ChairProperties::styles RecliningChair::style() const
{
	return chairImpl->style();
}

IChair& RecliningChair::setStyle(ChairProperties::styles aStyle)
{
	chairImpl->setStyle(aStyle);
	return *this;
}

double RecliningChair::capacity() const
{
	return chairImpl->capacity();
}

IChair& RecliningChair::setCapacity(double limit)
{
	chairImpl->setCapacity(limit);
	return *this;
}
