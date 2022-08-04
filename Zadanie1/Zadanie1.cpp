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
        std::getline(std::cin, s); // wczytuje az do napotkania znaku nowej linii

        int it = s.find_last_of(' ');
        
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


        if (shoppingList.find(product) != shoppingList.end() && s != "end")
        {

            std::cout << "Juz podales ten produkt:" << s << "! Co chcesz zrobic?\n";
            std::cout << "Wpisz 1 jeœli chcesz nadpisac" << std::endl;
            std::cout << "Wpisz 2 jeœli chcesz zsumowac (sumujemy obie wartoœci)" << std::endl;
            std::cout << "Wpisz 3 jeœli chcesz pominac (zostawiamy pierwsz¹ wartoœæ)" << std::endl;
            int choice;
            std::cin >> choice;


            std::map<std::string, int>::iterator it = shoppingList.find(product);
            

            switch (choice)
            {
            case 1:
                it->second = amount;
                shoppingList.insert({ product, amount });
                break;
            case 2:
                it->second = it->second + amount;
                shoppingList.insert({ product, amount });
                break;
            case 3:
                break;

            }
            choice = 0;

        }
        else
        {
            shoppingList.insert({ product, amount });
        }
        product = {};
        amountOfProduct = {};
        amount = 0;
    } while (s != "end");

    //std::cout << "Koniec" << std::endl;

    //for (auto el : shoppingList)
    //{
    //   std::cout << product << " " << amount << std::endl;
    //}

    //mapa, iterator na koniec jelsi nie znajdzie i wtedy kolejny
}

