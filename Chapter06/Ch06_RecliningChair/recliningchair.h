// file: recliningchair.h
// RecliningChair class definition
#ifndef RECLINING_CHAIR_H
#define RECLINING_CHAIR_H

class Recliner;    // forward declaration for Recliner class
class Chair_Impl;  // forward declaration for Chair_Impl class

#include "ChairProperties.h"
#include <memory>

class RecliningChair
{
private:
	std::unique_ptr<Chair_Impl> chairImpl;
	std::unique_ptr<Recliner> aRecliner;

public:
	// constructors and destructor
	RecliningChair();
	RecliningChair(ChairProperties::colors aColor, ChairProperties::styles aStyle);
	RecliningChair(RecliningChair &aChair);       // copy constructor
	~RecliningChair();                            // destructor

	// methods (behavior)
	double  sit(double weightOfPerson);
	double  getOff();
	double  addWeight(double aWeight);
	double  removeWeight(double aWeight);
	double  currentWeight() const;
	bool    isBroken() const;
	bool    isSitting() const;      // true if person seated
	void    clear();                // remove all load from chair
	void    refurbish();            // make the chair new again!
	void    setRecline(int anAngle);   // recline the seatback
	int     recline();                 // get recline angle

	// accessor functions for private data members
	ChairProperties::colors color() const;
	RecliningChair& setColor(ChairProperties::colors aColor);
	ChairProperties::styles style() const;
	RecliningChair& setStyle(ChairProperties::styles aStyle);
	double capacity() const;
	RecliningChair& setCapacity(double limit);
};

#endif// file: recliningchair.h
