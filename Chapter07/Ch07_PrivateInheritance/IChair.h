// file: ichair.h
// IChair interface definition
#ifndef ICHAIR_H
#define ICHAIR_H

#include "ChairProperties.h"

class IChair
{
public:
	// methods
	virtual double  sit(double weightOfPerson) = 0;
	virtual double  getOff() = 0;
	virtual double  addWeight(double aWeight) = 0;
	virtual double  removeWeight(double aWeight) = 0;
	virtual double  currentWeight() const = 0;
	virtual bool    isBroken() const = 0;
	virtual bool    isSitting() const = 0;         // true if person seated
	virtual void    clear() = 0;                   // remove all load from chair
	virtual void    refurbish() = 0;               // make the chair new again!

	// accessor functions for private data members
	virtual ChairProperties::colors color() const = 0;
	virtual IChair& setColor(ChairProperties::colors aColor) = 0;
	virtual ChairProperties::styles style() const = 0;
	virtual IChair& setStyle(ChairProperties::styles aStyle) = 0;
	virtual double capacity() const = 0;
	virtual IChair& setCapacity(double limit) = 0;
};

#endif// file: ichair.h
