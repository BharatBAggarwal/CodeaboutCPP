// Ch04_StreamFormating.cpp
//

#include "stdafx.h" // for visual studio
#include <cstdlib>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <algorithm>


int main(void)
{
	// sets width to 10 for first output field after std::setw()
	// width reverts to default value after printing “width 10”
	// “Hello” is printed with default width
	std::cout << std::setw(10) << "width 10"
		<< "Hello"
		<< std::endl; // prints “  width 10Hello”

	// the same result using member function
	std::cout.width(10);
	std::cout << "width 10" << "Hello" << std::endl;

	// sets width to 10 for first input field after std::setw()
	// width reverts to default value after reading inp1
	std::istringstream str("my width is 10");
	std::string inp1, inp2;
	str >> std::setw(10) >> inp1 >> inp2;
	// on input, inp1 is “my” and inp2 is “width”

	std::stringstream str10("my width is 10");
	std::string inp10, inp20;
	str10 >> std::noskipws
		>> std::setw(10) >> inp10   // inp10 is “my”
		>> inp20;                   // inp20 is “”
	str10 >> std::skipws;           // restore skipping whitespace

	// Print right justified with width 20
	std::cout.setf(std::ios::right, std::ios::adjustfield);
	std::cout.width(20);
	std::cout << "My width is 20"
		<< std::endl; // prints “      My width is 20”

	// Print left justified with width 20
	std::cout.setf(std::ios::left, std::ios::adjustfield);
	std::cout << std::setw(20)
		<< "My width is 20"
		<< std::endl; // prints “My width is 20      ”
	// restore default justification
	std::cout.unsetf(std::ios::adjustfield);

	// change fill character to ‘.’ using a manipulator
	std::cout << std::setfill('.') << std::setw(20)
		<< "My width is 20"
		<< std::endl; // prints “......My width is 20”
	// change fill character to ‘ ’ using member function
	std::cout.fill(' ');

	// using default precision of 6
	std::cout << 1234.56789    // prints 1234.56
		      << 3456789       // prints 3456789
		      << std::endl;

	// using precision of 4
	std::cout.precision(4);
	std::cout << 1234.56789    // prints 1235 (rounded up)
		      << 3456789       // prints 3456789
		      << std::endl;

	std::cout << std::setprecision(6) << std::endl;  // default 

	// Always show plus sign with integer
	std::cout.setf(std::ios::showpos);
	std::cout << 1234.56789    // prints +1234.56
		      << 3456789       // prints +3456789. No truncation!
		      << std::endl;
	std::cout.unsetf(std::ios::showpos);   // restore default

	// printing integers using different bases
	std::cout << "\n\n\nPrinting 10 using different bases"
		<< std::dec << "\n as decimal = " << 10   // 10
		<< std::oct << "\n as octal = " << 10     // 12
		<< std::hex << "\n as hex = " << 10       // a
		<< std::endl;

	// can also use member functions for changing base:
	// cout.setf(std::ios::dec, std::ios::basefield)
	// cout.setf(std::ios::hex, std::ios::basefield)
	// cout.setf(std::ios::oct, std::ios::basefield)

	// printing the base along with the integer
	std::cout.setf(std::ios::showbase);   // enable base display
	std::cout << "\n\n\nPrinting 10 with base display"
		<< std::dec << "\n as decimal = " << 10 // 10
		<< std::oct << "\n as octal = " << 10   // 012
		<< std::hex << "\n as hex = " << 10     // 0xa
		<< std::endl;
	std::cout.unsetf(std::ios::showbase); // disable showbase
	std::cout << std::dec << std::endl;   // restore decimal

	// To print hex numbers with uppercase alphanumerics use
	// std::cout.setf(std::ios::uppercase);
	// and
	// std::cout.unsetf(std::ios::uppercase);
	// or manipulators std::uppercase and std::nouppercase

	// Default behavior
	std::cout << 10.0                // displays 10
		      << 0.000011            // displays 1.1e-005
		      << 10000000.1          // displays 1e+007
		      << std::endl;

	// With ios::showpoint flag
	std::cout.setf(std::ios::showpoint);
	std::cout << 10.0                // displays 10.0000
		      << 0.000011            // displays 1.10000e-005
		      << 10000000.1          // displays 1.00000e+007
		      << std::endl;
	std::cout.unsetf(std::ios::showpoint);    // restore default

	// Using fixed notation
	std::cout.setf(std::ios::fixed, std::ios::floatfield);
	std::cout << 10.0            // displays 10.000000
		      << 0.000011        // displays 0.000011
		      << 10000000.1      // displays 10000000.100000
		      << std::endl;

	// Using scientific notation
	std::cout.setf(std::ios::scientific,
		std::ios::floatfield);
	std::cout << 10.0            // displays 1.000000e+001
		      << 0.000011        // displays 1.100000e-005
		      << 10000000.1      // displays 1.000000e+007
		      << std::endl;
	std::cout.unsetf(std::ios::floatfield); // use default

	std::cout << "Printing without std::boolalpha" << std::endl
		<< "true: " << true         // prints true: 1
		<< "false : " << false      // prints false: 0
		<< std::endl;
	std::cout << "Printing with std::boolalpha" << std::endl
		<< std::boolalpha
		<< "true: " << true         // prints true: true
		<< "false : " << false      // prints false: false
		<< std::noboolalpha << std::endl;

	//input using std::boolalpha
	bool binp1, binp2;
	std::istringstream str30("true false");
	str30 >> std::boolalpha
		  >> binp1
		  >> binp2;

	return EXIT_SUCCESS;
}

