// Ch05_NewChair.cpp
//

#include "stdafx.h"  // for visual studio
#include "newchair.h"
#include <iostream>

int main(void)
{
	Chair aChair(Chair::colors::red, Chair::styles::traditional);
	aChair.sit(50.0);       // person of weight 50 sits on chair
	aChair.addWeight(25.0); // add 25 additional weight
	std::cout << std::endl << "Properties of aChair:"
		<< std::endl
		<< "Weight : " << aChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aChair.color() << std::endl
		<< "Style : " << (int)aChair.style()
		<< std::endl << std::endl;

	Chair chair2;       // use default constructor
	chair2.sit(150.0);  // the chair will break. Capacity = 100.0
	chair2.refurbish(); // make the chair new again

	// chaining of function calls sequence breaks
	// at clear() because it returns void and not Chair&
	chair2.setColor(Chair::colors::green)
		  .setStyle(Chair::styles::modern)
		  .clear();
	std::cout << std::endl << "Properties of Chair2:"
		<< std::endl
		<< "Weight : " << chair2.currentWeight()
		<< std::endl
		<< "Color : " << (int)chair2.color() << std::endl
		<< "Style : " << (int)chair2.style()
		<< std::endl << std::endl;

	std::cout << std::endl
		<< "Active chairs: " << Chair::chairsActive()
		<< std::endl
		<< "Average Weight: " << Chair::averageWeight()
		<< std::endl;

	return EXIT_SUCCESS;
}
