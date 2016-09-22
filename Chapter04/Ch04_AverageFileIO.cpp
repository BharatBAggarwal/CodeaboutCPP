// AverageFileIO.cpp
//

#include "stdafx.h"  // for visual studio
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <sstream>   // already includes <string>
#include <ctime>
#include <vector>


// function to save data to file
int saveData(const std::string &filename,
	         const std::vector<double> &data,
	         const double average)
{
	// create file stream
	std::ofstream dataFile(filename.c_str(), std::ios::out);
	if (!dataFile)
	{
		std::cout << "Could not open file " << filename
			      << " for writing data" << std::endl;
		return EXIT_FAILURE;
	}

	// C++ library functions to get local date and time
	char strDateTime[128];
	std::time_t now = std::time(NULL);
	std::strftime(strDateTime, sizeof(strDateTime), "%A %c",
		          std::localtime(&now));

	dataFile.setf(std::ios::fixed, std::ios::floatfield);
	dataFile.precision(6);

	dataFile << "<<<<<<<<<< ------Data File : " << filename
		     << std::endl;
	dataFile << "<<<<<<<<<< Created by Average Calculator"
		     << std::endl;
	dataFile << "<<<<<<<<<< Created on: " << strDateTime
		     << std::endl;
	dataFile << "<<<<<<<<<< ------ Input Data"
		     << std::endl;
	dataFile << "How Many Numbers       : "
		     << data.size() << std::endl;

	dataFile << "<<<<<<<<<< ------ List of numbers"
		     << std::endl;
	for(auto num = data.begin();
		num != data.end();
		++num)
	{
		dataFile << "Number                 : "
			     << *num << std::endl;
	}

	dataFile << "<<<<<<<<<< ------ Output Data"
		     << std::endl;
	dataFile << "Average                : "
		     << average << std::endl;

	dataFile.close();   // close the data file
	return EXIT_SUCCESS;
}


// function to read data from file
int readData(const std::string &filename,
	         std::vector<double> &data)
{
	std::string buffer, label;

	std::ifstream dataFile(filename.c_str(), std::ios::in);
	if (!dataFile)
	{
		std::cout << "Could not open file " << filename
			      << " for reading data"    << std::endl;
		return EXIT_FAILURE;
	}

	// skip first 4 header lines
	std::getline(dataFile, buffer);
	std::getline(dataFile, buffer);
	std::getline(dataFile, buffer);
	std::getline(dataFile, buffer);

	double count;
	// read count of numbers
    // read line of data and create string stream
	std::getline(dataFile, buffer);
	std::stringstream aStream(buffer);
    // read label and value from string stream
	std::getline(aStream, label, ':');
	aStream >> count;

	// Skip list header
	std::getline(dataFile, buffer);

	double temp;
	// read count numbers
	for (int i = 0; i < count; ++i)
	{
		// read line of data and create string stream
		std::getline(dataFile, buffer);
		std::stringstream aStream(buffer);
		// read label and value from string stream
		std::getline(aStream, label, ':');
		aStream >> temp;
		data.push_back(temp);
	}

	// Skip rest of file. We only need to read input data
	dataFile.close();
	return EXIT_SUCCESS;
}


// function to calculate an average
// function to calculate an average
double average(const std::vector<double> &data)
{
	double sum = 0.0;

	// num points to current element
	for (auto num = data.begin();
		 num != data.end();
		 ++num)
	{
		sum += *num; // calculate sum
	}

	return (sum / data.size());
}


// the main function
int main()
{
	std::vector<double> numbers; // empty vector
	double avg;                  // average
	std::string filename;        // name of datafile

	// input name of data file
	std::cout << "Input name of data file : ";
	std::getline(std::cin, filename);

	// read data from file
	readData(filename, numbers);

	// calculate average
	avg = average(numbers);
	// After call to function, howMany contains numbers
	// actually used in average calculation

	// save data in file
	saveData(filename, numbers, avg);

	return EXIT_SUCCESS;
}
