// Ch04_IOStreamErrors.cpp
//

#include "stdafx.h" // for visual studio
#include <cstdlib>
#include <iostream>
#include <fstream>

// the main function
int main()
{
	long buffer[100];

	// open file for input
	std::ifstream inpFile("fileName", std::ios::in);
	if (!inpFile)
	{
		std::cout << "Error opening input file"
			<< std::endl;
		return EXIT_FAILURE;
	}

	// read data into buffer array
	for (int i = 0; i < 100; i++)
	{
		inpFile >> buffer[i];
		if (inpFile.eof())  // stop if at end of file
		{
			std::cout << "Reached end of file"
				<< std::endl;
			break;
		}

		if (inpFile.bad())  // stop if unrecoverable error
		{
			std::cout << "Unrecoverable error"
				<< std::endl;
			inpFile.close();       // close file
			return EXIT_FAILURE;
		}

		if (inpFile.fail())        // formatting error
		{
			inpFile.clear();       // clear error bits
			buffer[i] = 0.0;       // set value to 0.0
		}
	}

	inpFile.close();              // close file
	return EXIT_SUCCESS;
}

