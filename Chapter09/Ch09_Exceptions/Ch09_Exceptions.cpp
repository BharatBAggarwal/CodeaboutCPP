// Ch09_Exceptions.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include <exception>
#include <string>

// define error class
class DivideError : public std::exception
{
public:
	DivideError(std::string message)
	{
		errorName = message;
	}

	virtual const char* what() const throw()
	{
		return errorName.c_str();
	}

private:
	std::string errorName;
};

// function to perform division
double divide(double a, double b)
{
	// throw error object if b=0
	if (b == 0)
		throw DivideError("Attempt to divide by zero");

	return a / b;
}

// the main function
int main()
{
	double a, b, c;

	std::cout << "input numerator: ";
	std::cin >> a;
	std::cout << std::endl << "input denominator: ";
	std::cin >> b;

	try
	{
		c = divide(a, b);
		std::cout << "Result of division is: "
			      << c << std::endl;
	}

	catch (const DivideError& anError)
	{
		std::cout << anError.what() << std::endl;
	}

	catch (...)
	{
		std::cout << "Unknown exception" << std::endl;
	}

	std::cout << "First statement after Catch Blocks"
		      << std::endl;

	return EXIT_SUCCESS;
}


