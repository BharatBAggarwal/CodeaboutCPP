// file: chair_impl.h
// Chair_Impl class definition
#ifndef CHAIR_IMPL_H
#define CHAIR_IMPL_H

#include "ChairProperties.h"

class Chair_Impl
{

private:      // all data members are made private
	ChairProperties::colors acolor;
	ChairProperties::styles astyle;
	bool          broken;
	double        currentLoad;
	double        maxWeight;
	double        personWeight;
	double        addedWeight;

protected:
	double        setCurrentWeight();

public:
	// constructors and destructor
	Chair_Impl();
	Chair_Impl(ChairProperties::colors aColor, ChairProperties::styles aStyle);
	~Chair_Impl();                   // destructor

	// methods (behavior)
	double  sit(double weightOfPerson);
	double  getOff();
	double  addWeight(double aWeight);
	double  removeWeight(double aWeight);
	double  currentWeight() const;
	bool    isBroken() const;
	bool    isSitting() const; // true if person seated
	void clear();              // remove all load from chair
	void refurbish();          // make the chair new again!

	// accessor functions for private data members
	ChairProperties::colors color() const;
	Chair_Impl& setColor(ChairProperties::colors aColor);
	ChairProperties::styles style() const;
	Chair_Impl& setStyle(ChairProperties::styles aStyle);
	double capacity() const;
	Chair_Impl& setCapacity(double limit);
};

#endif