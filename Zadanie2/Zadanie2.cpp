// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>


int removeSpacesAndCountSize(std::string text)
{
    auto noSpaceEnd = std::remove(text.begin(), text.end(), ' ');
    text.erase(noSpaceEnd, text.end());

    int size;
    size = text.size();
    return size;
}


int main()
{
    std::ifstream file("zdania.csv");

    if (!file.is_open())
    {
        std::cout << "Nie uda³o siê otworzyc pliku";
        return 0;
    }
    std::string str;
    std::vector<std::string> strings;
    std::vector<int> numberOfWords;

    int space = 0;
    int max = 0;
    while (std::getline(file, str))
    {
        strings.push_back(str);
        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ')
            {
                space++;
            }
        }
        int words = space + 1;

        numberOfWords.push_back(words);

        space = 0;
        words = 0;
    }
    file.close();

    // Wypisz na konsolê: najd³u¿sze zdanie(najwiêcej s³ów)

    auto result = std::max_element(numberOfWords.begin(), numberOfWords.end());
    int maxElement = std::distance(numberOfWords.begin(), result);

    std::cout << "Najdluzsze zdanie (najwiecej slow) to: " << strings.at(maxElement);

    std::cout << std::endl;
    std::cout << std::endl;

    // Wypisz na konsolê: najkrotsze zdanie (najmniej s³ów)

    auto result2 = std::min_element(numberOfWords.begin(), numberOfWords.end());
    int minElement = std::distance(numberOfWords.begin(), result2);

    std::cout << "najkrotsze zdanie (najmniej slow) to: " << strings.at(minElement);

    std::cout << std::endl;
    std::cout << std::endl;

    // Wypisz na konsolê: najd³u¿sze zdanie(najwiêcej liter)

    std::vector<int> numberOfLetters;
    for (int i = 0; i < strings.size(); ++i)
    {
        int size = removeSpacesAndCountSize(strings.at(i));
        numberOfLetters.push_back(size);
    }

    auto result3 = std::max_element(numberOfLetters.begin(), numberOfLetters.end());
    int maxElement2 = std::distance(numberOfLetters.begin(), result3);

    std::cout << "Najdluzsze zdanie (najwiecej liter) to: " << strings.at(maxElement2) << " , zawiera: " << numberOfLetters.at(maxElement2) << " liter";

    std::cout << std::endl;
    std::cout << std::endl;

    //// Wypisz na konsolê: najkrotsze zdanie(najmniej liter)


    auto result4 = std::min_element(numberOfLetters.begin(), numberOfLetters.end());
    int minElement2 = std::distance(numberOfLetters.begin(), result4);

    std::cout << "najkrotsze zdanie (najmniej slow) to: " << strings.at(minElement2) << " , zawiera: " << numberOfLetters.at(minElement2) << " liter";

    std::cout << std::endl;

}