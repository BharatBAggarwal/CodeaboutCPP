// File markslist.cpp
// Implementation of class MarksList

#include "stdafx.h"
#include "marksList.h"
#include <iostream>
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

