#include <iostream>
#include "File.hpp"
#include "Employee.hpp"
#include "File.hpp"
#include <vector>

int main()
{
    Employee employee1("Jan", "Nowak", 5000);
    Employee employee2("Anna", "Nowak", 4500);
    Employee employee3("Karol", "Nowacki", 4000);
    Employee employee4("Karolina", "Nowak", 6000);
    Employee employee5("Jan", "Nowak", 5000);
    Employee employee6("Mi³osz", "Komar", 4500);
    Employee employee7("Karol", "Domanski", 4000);
    Employee employee8("Joanna", "Kownacki", 6000);
    Employee employee9("Przemys³aw", "Lekarski", 5000);
    Employee employee10("Krzysztof", "Profesorski", 4500);

    File file("Employees2.txt", File::OpenMode::WRITE);
    file.writeValue(employee1.getName());
    file.writeValue(employee1.getSurname());
    file.writeValue(employee1.getEmployeeNumber());
    file.writeValue(employee1.getSalary());

    std::vector<Employee> employees;
    employees.emplace_back("Jan", "Nowak", 5000);
    employees.push_back(Employee("Anna", "Nowak", 4500));


    //File file("C:\\Users\\mkandyba.MPD1\\source\\repos\\CPP_Zaawansowany\\Pliki\\Employees.txt", File::OpenMode::READ);
    //std::vector < std::vector < Employee > > MyVector;
    //std::vector<Employee> employeeVect;

    //employeeVect.
   


}