// File: irecliner.h
// IRecliner class definition

#ifndef IRECLINER_H
#define IRECLINER_H

class IRecliner
{
public:
	virtual void setAngle(int anAngle) = 0;
	virtual int angle() = 0;
	virtual void reset() = 0;
};

#endif
