// Ch02_Switch_Statement.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>

enum class Language : char { CPP, C, Java, Basic };

// the main function
int main()
{
	Language myFavorite;
	int choice;

	std::cout << "Choose your language: " << std::endl;
	std::cout << "   C++:   Enter 1" << std::endl;
	std::cout << "   C#:    Enter 2" << std::endl;
	std::cout << "   Java:  Enter 3" << std::endl;
	std::cout << "   Basic: Enter 4" << std::endl;
	std::cout << "Enter your choice: ";
	std::cin >> choice;

	// decrement choice by 1 and convert to myFavorite
	myFavorite = (Language)--choice;

	switch (myFavorite)
	{
	case Language::CPP:
		std::cout << "I love C++" << std::endl;
		break;
	case Language::Java:
		std::cout << "I love Java" << std::endl;
	case Language::C:
		std::cout << "I love C" << std::endl;
		break;
	case Language::Basic:
		std::cout << "I love Basic" << std::endl;
		break;
	default:
		std::cout << "None of the above" << std::endl;
		break;
	}

	return EXIT_SUCCESS;
}
