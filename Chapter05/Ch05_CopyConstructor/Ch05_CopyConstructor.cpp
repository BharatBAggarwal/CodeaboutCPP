// Ch05_CopyConstructor.cpp
//

#include "stdafx.h"  // for visual studio
#include "markslist.h"
#include <iostream>

int main(void)
{
	MarksList mathMarks;   // default constructor
	std::cout << "Number of Students: "
		      << mathMarks.students() << std::endl;

	MarksList mathMarks2(mathMarks); // copy constructor
	std::cout << "Number of Students in copy: "
		      << mathMarks2.students() << std::endl;

	return EXIT_SUCCESS;
}

