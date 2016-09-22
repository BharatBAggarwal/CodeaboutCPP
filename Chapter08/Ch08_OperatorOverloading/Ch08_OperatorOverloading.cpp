// Ch08_OperatorOverloading.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <iomanip>
#include "markslist.h"

int main()
	{
		std::ifstream inputFile("marks.txt");  // create stream
		MarksList aMarksList;
		inputFile >> aMarksList;    // read data into aMarksList
		inputFile.close();             // close input file

		std::ofstream report("markslist.txt"); // create stream
		report << aMarksList;                      // create markslist
		report.close();                        // close output file

		MarksList copiedList = aMarksList;     // copy constructor
		std::cout << "Copied Marks List:\n\n" << copiedList
			<< std::endl;

		MarksList aList(20);
		std::cout << "List before assignment:\n\n" << aList
			<< std::endl;
		aList = copiedList;                    // assignment operator
		std::cout << "List after assignment:\n\n" << aList
			<< std::endl;

		return EXIT_SUCCESS;
	}

