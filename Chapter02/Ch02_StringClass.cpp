// Ch02_StringClass.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <string>


int _tmain(int argc, _TCHAR* argv[])
{
	std::string hello = "Hello";
	std::string world("World");

	hello += " ";                      // hello is now “Hello “;
	std::string greet = hello + world; // greet = “Hello World”

	greet.compare("Hello World"); // result: (0 = same string)

	greet.c_str();              // returns a const pointer to a C style
                            	// null terminated string. Same as greet.data()
//	char buffer[10];
//	greet.copy(buffer, 8, 2);  // copy 8 characters from the
	                           // string starting from index 2 into buffer.
	std::string str = greet.substr(2, 8);   // extract 8 chars
                                        	// starting from index 2 to str.
	// character access: Supports indexed access with no
	// bounds checking and provides a range checked at() function.
	greet[2];       // ‘l’
	greet[2] = 'p'; // results in “Heplo World”

	greet.at(3);         // ‘l’. bounds checked.
	greet.at(3) = 'x';   // results in “Hepxo World”
	greet.front();       // returns first character
	greet.back();        // returns last character

	greet.insert(0, "Msg: ");       // insert “Msg: “ at index 0
	greet.insert(0, "1234 ", 2);    // insert 2 characters from “1234“ at index 0
	greet.erase(0, 2);              // remove 2 characters starting from index 0.
	greet.append(std::string("!!"));             // append characters. Same as +=
	// result: “Msg: Hepxo World!!”
	greet.replace(3, 2, " ? ? "); // replace 2 characters starting at index 3 with “??“                                               
	// result: “Msg??Hepxo World!!”
	// Search
	greet.find("Hep");   // find “Hep” in string. Result: 5
	greet.find('o');     // find char ‘o’ in string. Result: 9
	greet.find('o', 10); // find char ‘o’ in string starting
	// from index 10. Result: 12
	greet.find(' ? ');     // find char ‘?’ in string.
	// Result: 3
	greet.rfind(' ? ');    // find char ‘?’ in string starting
	// from end of string. Result: 4

	greet.max_size();          // maximum possible size for a string
	greet.capacity();          // number of characters that can be
	// stored in allocated memory
	greet.shrink_to_fit();     // free unused memory
	greet.reserve(500);      // increases capacity by 500
	greet.size();              // length of string. Same as length().
	greet.resize(100);         // changes length of string to 100

	// string modification
	greet.clear();         // erase all characters
	greet.empty();          // true if string has no characters

	return EXIT_SUCCESS;
}

