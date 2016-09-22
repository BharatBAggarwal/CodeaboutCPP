// Ch07_UsingInterfaces.cpp
//

#include "stdafx.h"  // for visual studio
#include "recliningchair.h"
#include <cstdlib>
#include <iostream>

void showChairDetails(IChair& aChair, IRecline& aRecline)
{
	aChair.sit(50.0);         // person of weight 50 sits on chair
	aChair.addWeight(25.0);   // add 25 additional weight
	aRecline.setRecline(20);  // recline seatbak 20 deg
	std::cout << std::endl << "Properties of Chair:"
		<< std::endl
		<< "Weight : " << aChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aChair.color() << std::endl
		<< "Style : " << (int)aChair.style()
		<< std::endl
		<< "Recline : " << aRecline.recline()
		<< std::endl << std::endl;
}


int main()
{
	// Create a RecliningChair object
	RecliningChair aRecliningChair(ChairProperties::colors::red,
                          ChairProperties::styles::traditional);

	// access RecliningChair methods through
	// IChair and IRecline interfaces
	showChairDetails(aRecliningChair, aRecliningChair);


    // access RecliningChair methods through object
	aRecliningChair.sit(150.0);  // the chair will break. Capacity = 100.0
	aRecliningChair.refurbish(); // make the chair new again
	aRecliningChair.setColor(ChairProperties::colors::green)
		           .setStyle(ChairProperties::styles::modern)
		           .clear();

	std::cout << std::endl << "Properties of Chair:"
		<< std::endl
		<< "Weight : " << aRecliningChair.currentWeight()
		<< std::endl
		<< "Color : " << (int)aRecliningChair.color() << std::endl
		<< "Style : " << (int)aRecliningChair.style()
		<< std::endl
		<< "Recline : " << aRecliningChair.recline()
		<< std::endl << std::endl;

	return EXIT_SUCCESS;
}
