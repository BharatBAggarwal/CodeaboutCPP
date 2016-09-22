// jasmine.cpp

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "jasmine.h"

Jasmine::Jasmine()
	: Jasmine("A Default Jasmine")
{
}

Jasmine::Jasmine(const std::string& aName)
	   : Flowers(aName)
{
}

Jasmine::~Jasmine()
{
}
