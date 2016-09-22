// Ch04_IOStreams.cpp
//

#include "stdafx.h" // for visual studio
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <string>

int main()
{
	int i = 0;
	double d = 0.0;
	std::string str;

	// read from cin
	std::cout << "Input: integer double string"
		<< std::endl;
	std::cin >> i >> d;
	std::getline(std::cin, str);

	// display values read from input
	std::cout << "Values read from input: " << std::endl;
	std::cout << "i = " << i << std::endl;
	std::cout << "d = " << d << std::endl;
	std::cout << "string = " << str << std::endl;

    // output string stream example
	std::string str2 = "Old characters: ";
	std::ostringstream aStrStream(str2, std::ios::app);

	d = 50.0;
	std::string add = " Appended Characters";
	aStrStream << d << add << std::ends;
	std::cout << aStrStream.str();

	return EXIT_SUCCESS;
}

