// rose.cpp

#include "stdafx.h"
#include <cstdlib>
#include <iostream>
#include "rose.h"

Rose::Rose()
	: Rose("A Rose by any other name ...")
{
}

Rose::Rose(const std::string& aName)
	: Flowers(aName)
{
}

Rose::~Rose()
{
}

Flowers::smells Rose::smell()
{
	return smells::Rose;
}
