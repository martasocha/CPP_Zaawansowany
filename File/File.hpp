#pragma once
#include <vector>

class Employee
{
	std::vector<Employee> vectEmployee; // wektor w mainie, kolejna klasa EmployeeList...
public:
	std::string _name;
	std::string _surname;
	int _empolyeeNumber;
	double _salary;

	int generateID;
	//std::string _fileName;
	Employee(std::string name, std::string surname, double salary);

	template<typename T>
	friend const File& operator<<(const File& file, T data);

	template<typename T>
	friend const File& operator>>(const File& file, T data);
};

class File
{
	std::vector<Employee> vectEmployee;
	std::fstream _filestream;
public:
	enum class OpenMode {
		WRITE,
		READ
	};
	File(const std::string& filePath, OpenMode openMode);
	~File();

};

template<typename T>
const File& operator<<(const File& file, T data)
{

}

template<typename T>
const File& operator>>(const File& file, T data)
{

}