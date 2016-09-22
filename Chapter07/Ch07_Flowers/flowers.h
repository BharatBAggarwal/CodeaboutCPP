// flowers.h

#ifndef FLOWERS_H
   #define FLOWERS_H

#include <string>

class Flowers
{
public:
	enum class smells { Pleasant, Rose, Jasmine, default };

private:
	std::string flowerName;

public:
	Flowers();
	Flowers(const std::string& aName);
	virtual ~Flowers();      // a virtual destructor
	virtual smells smell();  // a virtual smell() function
	const std::string& name() const;
	void setName(const std::string& aName);
};

#endif