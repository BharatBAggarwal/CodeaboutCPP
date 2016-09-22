// Ch07_Flowers01.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include <string>
#include <vector>
#include "flowers.h"
#include "rose.h"
#include "jasmine.h"

void smellFlowers(std::vector<Flowers*> &flowers)
{
	for (int i = 0; i < flowers.size(); ++i)
	{
		std::cout << "Smell of a " << flowers[i]->name()
			      << " is "        << (int)flowers[i]->smell()
			      << std::endl;
	}
}

// the main function
int main()
{
	// call smellFlowers() with an array of Roses
	std::cout << std::endl
		<< "Calling smellFlowers with Roses"
		<< std::endl;
	std::vector<Flowers*> roses(3);   // a vector of Roses
	roses[0] = new Rose("Red Rose");
	roses[1] = new Rose("White Rose");
	roses[2] = new Rose("Yellow Rose");
	smellFlowers(roses);
	std::cout << std::endl;

	// call smellFlowers() with an array of Jasmines
	std::cout << std::endl
		<< "Calling smellFlowers with Jasmines"
		<< std::endl;
	std::vector<Flowers*> jasmines(3);   // a vector of Jasmines
	jasmines[0] = new Jasmine("Fresh Jasmine");
	jasmines[1] = new Jasmine("California Jasmine");
	jasmines[2] = new Jasmine("New York Jasmine");
	smellFlowers(jasmines);
	std::cout << std::endl;

	return EXIT_SUCCESS;
}

