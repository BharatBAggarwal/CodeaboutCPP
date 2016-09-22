// jasmine.h

#ifndef JASMINE_H
	#define JASMINE_H

#include "flowers.h"

class Jasmine : public Flowers
{
public:
	Jasmine();
	Jasmine(const std::string& aName);
	virtual ~Jasmine();
};

#endif