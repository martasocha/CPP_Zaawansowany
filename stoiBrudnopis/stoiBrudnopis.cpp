// stoiBrudnopis.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>

int main()
{
    std::string number;
    std::cout << "Podaj wartosc do wczytania";
    //std::getline(std::cin, number);
    std::cin >> number;
    while (true)
    {
        int i = 0;
        try
        {
            i = std::stoi(number);
        }
        catch (const std::out_of_range& ex) // wyjatki lapiemy przez referencje, zeby uniknac kopiowania obiektow bledow, zaoszczezic na pamieci, zeby miec polimorfizm - kazdy ma metode ex.watch
        {
            std::cout << ex.what() << std::endl;
            std::cout << " Wartosc " << number << " jest za duza zeby zmiescic do int " << std::endl;
        }
        catch (const std::invalid_argument& ex)
        {
            std::cout << ex.what() << std::endl;
            std::cout << " Wartosc " << number << " jest za duza zeby zmiescic do int " << std::endl;
        }

        std::cout << "wartosc pobrana od uzytkownika " << number;
        std::cout << "i= " << i << std::endl;
    }
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
