// Ch03_FunctionArguments.cpp
//

#include "stdafx.h"               // for visual studio
#include <cstdlib>
#include <iostream>

void function1(long i, long j)    // pass by value
{
	i += j;
}

void function2(long* i, long* j)  // pass by pointer
{
	*i += *j;
}


void function3(long& i, long& j)  // pass by reference
{
	i += j;
}

// the main function
int main(void)
{
	long a = 10;     // a is 10
	long b = 20;     // b is 20

	std::cout << "a = " << a << " and b = " << b
		<< std::endl;

	function1(a, b);  // call method1. a and b not changed.
	std::cout << "After Method 1: a = " << a << " and b = " << b
		<< std::endl;

	function2(&a, &b); // call method2. a changed to 30.
	std::cout << "After Method 2: a = " << a << " and b = " << b
		<< std::endl;

	function3(a, b);   // call method3. a changed to 30.
	std::cout << "After Method 3: a = " << a << " and b = " << b
		<< std::endl;

	return EXIT_SUCCESS;
}
