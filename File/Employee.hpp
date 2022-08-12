#pragma once
#include <vector>
#include <string>

class Employee
{
	std::string _name;
	std::string _surname;
	int _empolyeeNumber;
	double _salary;
public:
	explicit Employee(std::string name, std::string surname, double salary); //pozwala wywolac niejawnie
	int generateID();

	//gettery
	std::string getName();
	std::string getSurname();
	int getEmployeeNumber();
	double getSalary();

	

};