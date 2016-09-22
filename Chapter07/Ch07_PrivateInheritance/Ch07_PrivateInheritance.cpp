// Ch07_PrivateInheritance.cpp
//
#include "stdafx.h"
#include "recliningchair.h"
#include <cstdlib>
#include <iostream>

int main()
{
	RecliningChair aChair(ChairProperties::colors::red,
		                  ChairProperties::styles::traditional);

	// inherited private methods accessible through object
	// because of access declaration
	aChair.sit(50.0);       // person of weight 50 sits on chair
	aChair.addWeight(25.0); // add 25 additional weight

	// IRecline interface used through the object
	aChair.setRecline(20);    // recline seatbak 20 deg

	std::cout << std::endl << "Properties of aChair:"
		<< std::endl
		<< "Weight : " << aChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aChair.color() << std::endl
		<< "Style : " << (int)aChair.style() << std::endl
		<< "Recline : " << aChair.recline()
		<< std::endl << std::endl;

	return EXIT_SUCCESS;
}
