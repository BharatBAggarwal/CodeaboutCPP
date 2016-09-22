// Ch06_RecliningChair.cpp
//

#include "stdafx.h"   // for visual studio
#include "recliningchair.h"
#include <cstdlib>
#include <iostream>


int main()
{
	RecliningChair aChair(ChairProperties::colors::red, ChairProperties::styles::traditional);
	aChair.sit(50.0);       // person of weight 50 sits on chair
	aChair.addWeight(25.0); // add 25 additional weight
	aChair.setRecline(20);  // recline seatbak 20 deg
	std::cout << std::endl << "Properties of aChair:"
		<< std::endl
		<< "Weight : " << aChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aChair.color() << std::endl
		<< "Style : " << (int)aChair.style()
		<< std::endl
		<< "Recline : " << aChair.recline()
		<< std::endl << std::endl;

	RecliningChair chair2;       // use default constructor
	chair2.sit(150.0);  // the chair will break. Capacity = 100.0
	chair2.refurbish(); // make the chair new again

	// chaining of function calls sequence breaks
	// at clear() because it returns void and not Chair&
	chair2.setColor(ChairProperties::colors::green)
		.setStyle(ChairProperties::styles::modern)
		.clear();
	std::cout << std::endl << "Properties of Chair2:"
		<< std::endl
		<< "Weight : " << chair2.currentWeight()
		<< std::endl
		<< "Color : " << (int)chair2.color() << std::endl
		<< "Style : " << (int)chair2.style()
		<< std::endl
		<< "Recline : " << chair2.recline()
		<< std::endl << std::endl;

	return EXIT_SUCCESS;
}

