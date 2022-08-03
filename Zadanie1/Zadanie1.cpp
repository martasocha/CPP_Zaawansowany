// Zadanie1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>

int main()
{
    std::cout << "Podaj liste produktow spozywczych i ich ilosc. Jeœli chcesz zakonczyc wczytywanie produktow wpisz: end; " << std::endl;
    std::string s;
    std::string product;
    std::string amountOfProduct;
    int amount = 0;
    std::map<std::string, int> shoppingList;

    do
    {
        std::cout << "Podaj nazwe produktu: ";
        std::getline(std::cin, s, ';'); // wczytuje az do napotkania znaku nowej linii

        int it = s.find_first_of(' ');
        for (int i = 0; i < it; ++i)
        {
            s[i] = std::tolower(s[i]);
            product += s[i];
        }
        for (int i = it+1; i < s.length(); ++i)
        {
            amountOfProduct += s[i];
        }
        amount = std::atoi(amountOfProduct.c_str());

        shoppingList.insert({ product, amount });

    } while (s != "end;");

    std::cout << "Koniec" << std::endl;

    for (auto el : shoppingList)
    {
        std::cout << product << " " << amount << std::endl;
    }

    //mapa, iterator na koniec jelsi nie znajdzie i wtedy kolejny
}

