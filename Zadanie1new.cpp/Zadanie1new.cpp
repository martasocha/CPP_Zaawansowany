// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>

int main()
{
    std::ifstream file("zdania.csv");

    if (!file.is_open())
    {
        std::cout << "Nie uda�o si� otworzyc pliku";
        return 0;
    }
    std::string str;
    std::vector<std::string> strings;
    std::vector<int> vectOfSpaces;
    //std::map<std::string, int> mapOfWords;
    int space = 0;
    int max = 0;
    while (std::getline(file, str))
    {
        strings.push_back(str);
        //std::cout << str << std::endl;
        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ')
            {
                space++;
            }
        }
        int words = space + 1;

        vectOfSpaces.push_back(words);


        std::sort(vectOfSpaces.begin(), vectOfSpaces.end());

        //std::cout << words << std::endl;
        if (words > max)
        {
            max = words;
        }

        space = 0;
        words = 0;
    }
    file.close();

    //auto it = std::max_element(vectOfSpaces.begin(), vectOfSpaces.end());
    vecOfSpaces.index(max(vecOfSpaces));
    std::cout << vectOfSpaces[it];
    /*for (auto [str, words] : mapOfWords)
    {

    }*/
    //std::cout << "Max wynosi: " << max << std::endl;

    //std::cout << "Wczytano " << strings.size() << " �ancuch�w";

}
