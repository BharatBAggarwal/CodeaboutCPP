// File markslist.cpp
// Implementation of class MarksList

#include "stdafx.h"
#include "marksList.h"
#include <iostream>
#include <iomanip>
#include <limits>
#include <cmath>

MarksList::MarksList(short students)
{
	numberOfStudents = students;

	// allocate memory for marks array
	marks.resize(students);

	for (int i = 0; i < marks.size(); ++i)
	{
		marks[i] = rand() % 100 + 1;
	}
}

MarksList::MarksList(const MarksList &aList)
{
	// copy data from aList to this list
	numberOfStudents = aList.students();

	marks.resize(numberOfStudents);
	// copy array from aList into marks
	for (int i = 0; i < marks.size(); ++i)
		marks[i] = aList.getMarks(i);
}

MarksList::~MarksList()
{
}

short MarksList::students() const
{
	return numberOfStudents;
}

double MarksList::getMarks(short studentID) const
{
	return marks[studentID];
}

MarksList& MarksList::operator=(const MarksList &rhs)
{
	if (this == &rhs)  // guard against self assignment
	{
		return *this;
	}

	// copy data from rhs to this list
	numberOfStudents = rhs.students();

	marks.resize(numberOfStudents);
	// copy array from rhs into marks
	for (int i = 0; i < marks.size(); ++i)
		marks[i] = rhs.getMarks(i);

	return *this;
}

std::ostream& operator<<(std::ostream &os,
	const MarksList &aList)
{
	os << "Marks List" << "\n\n"
	   << "Number of Students: "
	   << aList.numberOfStudents << "\n\n"
	   << "Student ID     Marks" << std::endl;

	os << std::setprecision(2) << std::fixed;
	for (int i = 0; i < aList.numberOfStudents; ++i)
	{
		os << std::setw(10)  << i + 1
		   << std::setw(10)  << aList.marks[i] << std::endl;
	}
	os << "-----------------------" << std::endl;
	return os;
}

std::istream& operator>>(std::istream &is,
	MarksList &aList)
{
	is >> aList.numberOfStudents;
	is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

//	for (int i = 0; i < aList.numberOfStudents; ++i)
	int i = 0;
	while (!is.eof())
		{
		is >> aList.marks[i];  // store marks in the array
		is.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		++i;
	    }
	aList.numberOfStudents = i;

	return is;
}
