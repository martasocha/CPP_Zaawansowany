#pragma once
#include <vector>

class Employee
{
	std::vector<Employee> vectEmployee;
public:
	std::string _name;
	std::string _surname;
	int _empolyeeNumber;
	double _salary;
	//std::string _fileName;
	Employee(std::string name, std::string surname, double salary);

};

class File
{
	std::vector<Employee> vectEmployee;
	std::string _fileName;
public:
	File(const std::string& fileName);
	~File();

};


const File& operator<<(const File& file, std::vector<Employee> vectEmployee);
const File& operator>>(const File& file, std::vector<Employee> vectEmployee);