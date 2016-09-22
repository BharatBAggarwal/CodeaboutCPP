// file: chair.cpp
// RecliningChair class implementation

#include "stdafx.h"
#include "recliningchair.h"
#include "recliner.h"
#include "chair_impl.h"
#include <cstdlib>
#include <iostream>

RecliningChair::RecliningChair()
	: RecliningChair(ChairProperties::colors::black, ChairProperties::styles::basic)
{
}

RecliningChair::RecliningChair(ChairProperties::colors aColor, ChairProperties::styles aStyle)
{
	chairImpl = std::unique_ptr<Chair_Impl>(new Chair_Impl(aColor, aStyle));
	aRecliner = std::unique_ptr<Recliner>(new Recliner());
}

RecliningChair::RecliningChair(RecliningChair& aChair)
{
	chairImpl = std::unique_ptr<Chair_Impl>(new Chair_Impl());
	chairImpl->setCapacity(aChair.capacity());
	chairImpl->setColor(aChair.color());
	chairImpl->setStyle(aChair.style());

	aRecliner = std::unique_ptr<Recliner>(new Recliner());
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

RecliningChair& RecliningChair::setColor(ChairProperties::colors aColor)
{
	chairImpl->setColor(aColor);
	return *this;
}

ChairProperties::styles RecliningChair::style() const
{
	return chairImpl->style();
}

RecliningChair& RecliningChair::setStyle(ChairProperties::styles aStyle)
{
	chairImpl->setStyle(aStyle);
	return *this;
}

double RecliningChair::capacity() const
{
	return chairImpl->capacity();
}

RecliningChair& RecliningChair::setCapacity(double limit)
{
	chairImpl->setCapacity(limit);
	return *this;
}
