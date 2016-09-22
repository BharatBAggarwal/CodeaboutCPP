// file: smartchair.h
// SmartChair class definition
#ifndef SMARTCHAIR_H
#define SMARTCHAIR_H

#include "chair.h" // required for Chair class

class SmartChair : public Chair
{
private:
	static double cumulativeWeight;  // class variable
	static long numberOfPersons;     // class variable
	static long chairCounter;        // class variable

public:
	SmartChair();
	SmartChair(colors aColor, styles aStyle);
	~SmartChair();

	double sit(double personWeight); // overriden function

	static long chairsActive();     // class function
	static double averageWeight();  // class function
};

#endif
