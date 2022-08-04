// Zadanie1.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <cstdlib>
#include <map>
#include <fstream>

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
            std::cout << "Wpisz 1 jesli chcesz nadpisac" << std::endl;
            std::cout << "Wpisz 2 jesli chcesz zsumowac (sumujemy obie wartosci)" << std::endl;
            std::cout << "Wpisz 3 jesli chcesz pominac (zostawiamy pierwsza wartosc)" << std::endl;
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


    std::string fileName("C:\\Users\\mkandyba.MPD1\\source\\repos\\CPP_Zaawansowany\\Zadanie1\\ShoppingList.txt");
    std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);

    if (fileToWrite.is_open())
    {
        //for (int i = 0; i <= shoppingList.size(); ++i)
        //{
        //    if (fileToWrite.good())
        //    {
        //        fileToWrite << shoppingList.first << " " << amount;

        //    }
        //}

        for (auto& kv : shoppingList) {
            fileToWrite << kv.first << kv.second << '\n';
        }
        fileToWrite.close();
    }
    else
    {
        std::cout << "Nie moge otworzyc pliku do zapisu";
        return -1;
    }

    //std::cout << "Koniec" << std::endl;

    //for (auto el : shoppingList)
    //{
    //   std::cout << product << " " << amount << std::endl;
    //}

    //mapa, iterator na koniec jelsi nie znajdzie i wtedy kolejny
}

