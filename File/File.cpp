// File.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "File.hpp"
#include<fstream>
#include <string>
#include <random>
#include <algorithm>
#include <numeric>

Employee::Employee(std::string name, std::string surname, double salary): 
	_name(name),
	_surname(surname),
	_salary(salary)
{
	int employeeNumber;
	std::random_device randomDevice;
	std::default_random_engine defaultEngine(randomDevice());
	std::uniform_int_distribution<int> intDistribution(1, 100);

	employeeNumber= intDistribution(defaultEngine);
	this->_empolyeeNumber = employeeNumber;
}

File::File(const std::string& filePath, OpenMode openMode) :
{

	if (openMode == OpenMode::READ)
	{
		_filestream = std::fstream(filePath, std::ios::in); //_filestream uchwyt do pliku
	}
	else if (openMode == OpenMode::WRITE)
	{
		_filestream = std::fstream(filePath, std::ios::in);
	}
	else
	{

	}
}

File::~File()
{
	
	_filestream.close();
}

const File& operator<<(const File& file, std::vector<Employee> vectEmployee)
{
	std::string _fileName("C:\\Users\\mkandyba.MPD1\\source\\repos\\CPP_Zaawansowany\\Pliki\\Workers.txt");
	std::ofstream fileToWrite(_fileName, std::ios::out | std::ios::trunc);

	for (int i = 0; i < 10; i++)
	{
		fileToWrite << vectEmployee[i]._name << vectEmployee[i]._surname << vectEmployee[i]._empolyeeNumber << vectEmployee[i]._salary;
		i++;
	}
	return file;
	fileToWrite.close();
}
