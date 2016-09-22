// file: recliningchair.h
// RecliningChair class definition
#ifndef RECLINING_CHAIR_H
#define RECLINING_CHAIR_H

#include "IChair.h"
#include "IRecline.h"
#include "IRecliner.h"
#include <memory>

class RecliningChair : public IChair,
	                   public IRecline
{
private:
	std::unique_ptr<IChair> chairImpl;
	std::unique_ptr<IRecliner> aRecliner;

public:
	// constructors and destructor
	RecliningChair();
	RecliningChair(ChairProperties::colors aColor, ChairProperties::styles aStyle);
	RecliningChair(RecliningChair &aChair);       // copy constructor
	virtual ~RecliningChair();                    // destructor

	// IChair methods
	virtual double  sit(double weightOfPerson);
	virtual double  getOff();
	virtual double  addWeight(double aWeight);
	virtual double  removeWeight(double aWeight);
	virtual double  currentWeight() const;
	virtual bool    isBroken() const;
	virtual bool    isSitting() const;      // true if person seated
	virtual void    clear();                // remove all load from chair
	virtual void    refurbish();            // make the chair new again!

	// IRecline methods
	virtual void    setRecline(int anAngle);   // recline the seatback
	virtual int     recline();                 // get recline angle

	// accessor functions for private data members
	virtual ChairProperties::colors color() const;
	virtual IChair& setColor(ChairProperties::colors aColor);
	virtual ChairProperties::styles style() const;
	virtual IChair& setStyle(ChairProperties::styles aStyle);
	virtual double capacity() const;
	virtual IChair& setCapacity(double limit);
};

#endif// file: recliningchair.h
