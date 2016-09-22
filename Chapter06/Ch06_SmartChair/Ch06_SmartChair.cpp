// Ch06_SmartChair.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include "smartchair.h"

// the main function
int main()
{
	SmartChair aChair(Chair::colors::red, Chair::styles::modern);
	aChair.sit(50.0);       // person of weight 50 sits on chair
	aChair.addWeight(25.0); // add 25 additional weight
	std::cout << std::endl << "Properties of aChair:"
		<< std::endl
		<< "Weight : " << aChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aChair.color() << std::endl
		<< "Style : " << (int)aChair.style()
		<< std::endl << std::endl;

	SmartChair chair2;  // use default constructor
	chair2.sit(150.0);  // the chair will break. Capacity = 100.0
	chair2.refurbish(); // make the chair new again

	chair2.setColor(Chair::colors::green)
	      .setStyle(Chair::styles::modern)
	      .clear();     // set weight to 0.0
	std::cout << std::endl << "Properties of Chair2:"
		<< std::endl
		<< "Weight : " << chair2.currentWeight()
		<< std::endl
		<< "Color : " << (int)chair2.color() << std::endl
		<< "Style : " << (int)chair2.style()
		<< std::endl << std::endl;

	std::cout << std::endl
		<< "Active Chairs : " << SmartChair::chairsActive()
		<< std::endl
		<< "Average Weight: " << SmartChair::averageWeight()
		<< std::endl << std::endl;

	return EXIT_SUCCESS;
}

