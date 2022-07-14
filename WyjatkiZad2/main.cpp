#include <iostream>
#include "PostiveNumber.hpp"

int main()
{
    double a = 0;
    float b = 0;
    int c = 0;
    double d = 0;

    std::cout << "Podaj liczbe typu double: ";
    std::cin >> a;
    std::cout << "Podaj liczbe typu float: ";
    std::cin >> b;
    std::cout << "Podaj liczbe typu int: ";
    std::cin >> c;

    while (true)
    {
        try
        {

            PositiveNumber num1(a);
            PositiveNumber num2(b);
            PositiveNumber num3(c);

            //std::cout << "Podane liczby to" << num1.getValue() << " " << num2.getValue() << " " << num3.getValue() << std::endl;

            std::cout << "Podaj liczbe ktora chcesz dodac: ";
            std::cin >> d;
            num1.add(d);
            std::cout << "wynik wynosi: " << num1.getValue() << std::endl;

            std::cout << "Podaj liczbe ktora chcesz odjac: ";
            std::cin >> d;
            num1.substract(d);
            std::cout << "wynik wynosi: " << num1.getValue() << std::endl;

        }
        catch (std::string& error)
        {
            std::cout << error << std::endl;
        }
    }


}