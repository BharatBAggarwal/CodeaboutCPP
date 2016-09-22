// flowers.cpp

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "flowers.h"

Flowers::Flowers()
	   : Flowers("Base class flower")
{
}

Flowers::Flowers(const std::string& aName)
{
	setName(aName);
}

Flowers::~Flowers()
{
}

Flowers::smells Flowers::smell()
{
	return smells::default;
}

const std::string& Flowers::name() const
{
	return flowerName;
}

void Flowers::setName(const std::string& aName)
{
	if (aName.size() > 0)
		flowerName = aName;
	else
		flowerName = "You can call me ...";
}
