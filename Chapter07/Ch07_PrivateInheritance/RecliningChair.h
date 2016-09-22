// file: recliningchair.h
// RecliningChair class definition
#ifndef RECLINING_CHAIR_H
#define RECLINING_CHAIR_H

#include "IChair.h"
#include "Chair_Impl.h"
#include "IRecline.h"
#include "IRecliner.h"
#include "Recliner.h"
#include "ChairProperties.h"
#include <memory>

class RecliningChair : public virtual IChair,
	public virtual IRecline,
	private Recliner,
	private Chair_Impl
{
public:
	// constructors and destructor
	RecliningChair();
	RecliningChair(ChairProperties::colors aColor, ChairProperties::styles aStyle);
	virtual ~RecliningChair();                       // destructor

	// IRecline interface (not a part of Chair_Impl)
	void virtual setRecline(int anAngle);   // recline the seatback
	int virtual recline();                  // get recline angle

	// IChair interface inherited from Chair_Impl
	// access declaration to retore public access for Chair::Impl
	// methods so that they can be called from a RecliningChair object
	Chair_Impl::sit;
	Chair_Impl::getOff;
	Chair_Impl::addWeight;
	Chair_Impl::removeWeight;
	Chair_Impl::currentWeight;
	Chair_Impl::isBroken;
	Chair_Impl::isSitting;     // true if person seated
	Chair_Impl::clear;         // remove all load from chair
	Chair_Impl::refurbish;     // make the chair new again!

	// accessor functions for private data members
	Chair_Impl::color;
	Chair_Impl::setColor;
	Chair_Impl::style;
	Chair_Impl::setStyle;
	Chair_Impl::capacity;
	Chair_Impl::setCapacity;
};

#endif// file: recliningchair.h
