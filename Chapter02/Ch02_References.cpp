// Cho2_References.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"  // for visual studio
#include <iostream>
#include <cstdlib>

// the main function
//int _tmain(int argc, _TCHAR* argv[])
int main()
{
	long aVariable = 123;
	long& refVariable = aVariable;

	// both statements output 123
	std::cout << aVariable << std::endl;
	std::cout << refVariable << std::endl;

	// change in myVariable also shows by refMyVariable
	aVariable = 1000 * aVariable;
	std::cout << aVariable << std::endl;     // 123000
	std::cout << refVariable << std::endl;   // 123000

	refVariable = 1000;                      // no de-referencing syntax
	std::cout << aVariable << std::endl;     // 1000
	std::cout << refVariable << std::endl;   // 1000

	return EXIT_SUCCESS;
}

