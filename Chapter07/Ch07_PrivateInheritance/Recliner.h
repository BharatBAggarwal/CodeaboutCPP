// File: recliner.h - Recliner class definition
//
#ifndef RECLINER_H
#define RECLINER_H

#include "IRecliner.h"

class Recliner : public IRecliner
{
private:
	int seatbackAngle;

public:
	Recliner();
	Recliner(int anAngle);
	virtual ~Recliner();
	virtual void setAngle(int anAngle);
	virtual int angle();
	virtual void reset();
};

#endif