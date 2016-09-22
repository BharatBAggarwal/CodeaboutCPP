// rose.h

#ifndef ROSE_H
	#define ROSE_H

#include "flowers.h"

class Rose : public Flowers
{
public:
	Rose();
	Rose(const std::string& aName);
	virtual ~Rose();
	virtual smells smell();
};

#endif