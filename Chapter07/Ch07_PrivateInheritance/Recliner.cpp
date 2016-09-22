// File: recliner.cpp
// Recliner class implementation

#include "stdafx.h"
#include "recliner.h"

Recliner::Recliner()
	: Recliner(0)
{
}

Recliner::Recliner(int anAngle)
{
	seatbackAngle = anAngle;
}

Recliner::~Recliner()
{
}

void Recliner::setAngle(int anAngle)
{
	seatbackAngle = anAngle;
}

int Recliner::angle()
{
	return seatbackAngle;
}

void Recliner::reset()
{
	seatbackAngle = 0;
}
