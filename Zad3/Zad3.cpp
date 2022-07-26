// Zad3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>

bool contains(const std::set<std::string>& container)
{
    return container.find("abcdefghijklmnoprstuwxyz") != container.end();
}

int main()
{
    //std::set<std::string> alphabet1 = { "abcdefghijklmnoprstuwxyz"};
    std::set<std::string> alphabet = {"abcefghijkuwxyz"};

    if (contains(alphabet))
    {
        std::cout << "W podanym lancuchu znakow wystepuja wszystkie litery alfabetu" << std::endl;
    }
    else
    {
        std::cout << "W podanym lancuchu znakow nie wystepuja wszystkie litery alfabetu" << std::endl;
    }

}


