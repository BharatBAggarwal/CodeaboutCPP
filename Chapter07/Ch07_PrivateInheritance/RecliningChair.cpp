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
	: Recliner(),
	  Chair_Impl(aColor, aStyle)
{
}

RecliningChair::~RecliningChair()
{
}

int RecliningChair::recline()
{
	return angle();
}

void RecliningChair::setRecline(int anAngle)
{
	return setAngle(anAngle);
}

