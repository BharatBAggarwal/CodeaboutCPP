// Ch02_ReverseArray.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>

int _tmain(int argc, _TCHAR* argv[])
{
	int x[10] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 }, // declare array
		temp;              // temp variable

	int *start = &x[0],    // point to first element
		*end = &x[9];      // point to last element

	// Loop while start points to a location in the array
	// that is before the location of the end pointer
	while (start < end)      // compare pointers
	{
		// store value pointed to by start in temp
		temp = *start;

		// Store value pointed to by end in start
		// Then use post-increment to point start to the
		// next element
		*start++ = *end;

		// store value in temp in end element.
		// Then use post-decrement to point end to the
		// previous element
		*end-- = temp;
	}

	return EXIT_SUCCESS;
}

