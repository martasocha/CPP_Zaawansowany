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
        std::string s = {};
        std::cin.ignore();
        std::getline(std::cin, s); // wczytuje az do napotkania znaku nowej linii

        for (int i = 0; i < s.length(); ++i)
        {
            s[i] = std::tolower(s[i]);
            product += s[i];
        }
        int amount = 0;
        std::cout << "Podaj ilosc produktu: ";
        std::cin >> amount;

        shoppingList.insert({ product, amount });
        
    } while (product != "end");

    std::cout << "Koniec" << std::endl;

    //for (auto el : shoppingList)
    //{
    //    std::cout << product << " " << amount << std::endl;
    //}

    //mapa, iterator na koniec jelsi nie znajdzie i wtedy kolejny
}

