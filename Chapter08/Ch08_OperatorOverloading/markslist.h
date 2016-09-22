// File markslist.h
// Definition of class MarksList
#ifndef MARKSLIST_H
#define MARKSLIST_H

#include <vector>

class MarksList
{
private:
	short numberOfStudents;
	std::vector<double>marks;           // vector to store marks

public:
	MarksList(short students = 100);    // constructor
	MarksList(const MarksList &aList);  // copy constructor
	~MarksList();                       // destructor
	short students() const;
	double getMarks(short studentID) const;

	//overloaded operators
	MarksList& operator= (const MarksList &rhs);
	friend std::ostream& operator<< (std::ostream &os,
		                             const MarksList &aList);
	friend std::istream& operator>> (std::istream &is,
		                             MarksList &aList);
};

#endif