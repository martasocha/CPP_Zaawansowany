#include <iostream>
#include "Employee.hpp"
#include <random>

Employee::Employee(std::string name, std::string surname, double salary) :
	_name(name),
	_surname(surname),
	_salary(salary)
{
	this->_empolyeeNumber = generateID();
}

int Employee::generateID()
{
	int employeeNumber;
	std::random_device randomDevice;
	std::default_random_engine defaultEngine(randomDevice());
	std::uniform_int_distribution<int> intDistribution(1, 100);

	employeeNumber = intDistribution(defaultEngine);
	
	return employeeNumber;
}

std::string Employee::getName()
{
	return _name;
}

std::string Employee::getSurname()
{
	return _surname;
}

int Employee::getEmployeeNumber()
{
	return _empolyeeNumber;
}

double Employee::getSalary()
{
	return _salary;
}
