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

File::File(const std::string& fileName):
	_fileName(fileName)
{

	//std::string _fileName("C:\\Users\\mkandyba.MPD1\\source\\repos\\CPP_Zaawansowany\\Pliki\\Workers.txt");
	std::ofstream fileToWrite(_fileName, std::ios::out | std::ios::trunc);

	if (fileToWrite.is_open())
	{
		for (int i = 0; i < 10; ++i)
		{
			fileToWrite << vectEmployee[i]._name << vectEmployee[i]._surname << vectEmployee[i]._empolyeeNumber << vectEmployee[i]._salary << "\n";
			i++;
		}
	}
	else
	{
		std::cout << "Nie mogê otworzyæ pliku do zapisu";
	}
	fileToWrite.close();
}


File::~File()
{
	
	//_fileName.close();
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
