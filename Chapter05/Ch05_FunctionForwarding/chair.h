// file: chair.h
// Chair class definition
#ifndef CHAIR_DEL_H
#define CHAIR_DEL_H

class Chair_Impl;  // forward declaration for implementation class
#include "ChairProperties.h"
#include <memory>

class Chair
{
private:
	std::unique_ptr<Chair_Impl> chairImpl;

public:
	// constructors and destructor
	Chair();
	Chair(ChairProperties::colors aColor, ChairProperties::styles aStyle);
	Chair(Chair& aChair);
	~Chair();

	// methods (behavior)
	double  sit(double weightOfPerson);
	double  getOff();
	double  addWeight(double aWeight);
	double  removeWeight(double aWeight);
	double  currentWeight() const;
	bool    isBroken() const;
	bool    isSitting() const; // true if person seated
	void    clear();              // remove all load from chair
	void    refurbish();          // make the chair new again!

	// accessor functions for private data members
	ChairProperties::colors color() const;
	Chair& setColor(ChairProperties::colors aColor);
	ChairProperties::styles style() const;
	Chair& setStyle(ChairProperties::styles aStyle);
	double capacity() const;
	Chair& setCapacity(double limit);
};

#endif