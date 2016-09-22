// Ch02_IF_Statement.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <cstdlib>
#include <iostream>

// the main function
int main()
{
	int choice;

	std::cout << "Choose your language: " << std::endl;
	std::cout << "   C++ :  Enter 1" << std::endl;
	std::cout << "   C   :  Enter 2" << std::endl;
	std::cout << "   Java:  Enter 3" << std::endl;
	std::cout << "   Basic: Enter 4" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	if (choice == 1)
	{
		std::cout << "I love C++" << std::endl;
	}
	else if (choice == 2)
	{
		std::cout << "I love C" << std::endl;
	}
	else if (choice == 3)
	{
		std::cout << "I love Java" << std::endl;
	}
	else if (choice == 4)
	{
		std::cout << "I love Basic" << std::endl;
	}
	else
	{
		std::cout << "None of the above" << std::endl;
	}

	return EXIT_SUCCESS;
}

