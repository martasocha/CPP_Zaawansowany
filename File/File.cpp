// File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "File.hpp"
#include <fstream>
#include <string>
#include <algorithm>
#include <numeric>
#include "Employee.hpp"
#include <vector>


File::File(const std::string& filePath, OpenMode openMode)
{

	if (openMode == OpenMode::READ)
	{
		_filestream = std::fstream(filePath, std::ios::in); //_filestream uchwyt do pliku
	}
	else if (openMode == OpenMode::WRITE)
	{
		_filestream = std::fstream(filePath, std::ios::out);
	}
	else
	{

	}
}



File::~File()
{
	_filestream.close();
}
