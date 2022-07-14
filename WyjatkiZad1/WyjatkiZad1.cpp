#include <iostream>

double divide(double a, double b)
{
    if (b == 0)
    {
        throw std::string("b nie moze byc rowne 0");
    }
    return a / b;

}


int main()
{
    int a = 0;
    int b = 0;
    while (true)
    {
        std::cout << "Podaj pierwsza liczbe: ";
        std::cin >> a;
        std::cout << "Podaj druga liczbe: ";
        std::cin >> b;


        try
        {
            double wynik = divide(a, b);
            std::cout << "Wynik dzielenia: " << wynik << std::endl << std::endl;
        }
        catch (std::string& error)
        {
            std::cout << error << std::endl;
        }
    }

}

