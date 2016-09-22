// file: chair_impl.h
// Chair_Impl class definition
#ifndef CHAIR_IMPL_H
#define CHAIR_IMPL_H

#include "ChairProperties.h"
#include "ichair.h"

class Chair_Impl : public virtual IChair
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
	virtual  ~Chair_Impl();                   // destructor

	// methods (behavior)
	virtual double  sit(double weightOfPerson);
	virtual double  getOff();
	virtual double  addWeight(double aWeight);
	virtual double  removeWeight(double aWeight);
	virtual double  currentWeight() const;
	virtual bool    isBroken() const;
	virtual bool    isSitting() const;    // true if person seated
	virtual void    clear();              // remove all load from chair
	virtual void    refurbish();          // make the chair new again!

	// accessor functions for private data members
	virtual ChairProperties::colors color() const;
	virtual IChair& setColor(ChairProperties::colors aColor);
	virtual ChairProperties::styles style() const;
	virtual IChair& setStyle(ChairProperties::styles aStyle);
	virtual double capacity() const;
	virtual IChair& setCapacity(double limit);
};
#endif