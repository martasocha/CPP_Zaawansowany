// Zadanie2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <algorithm>
#include <map>
#include <set>


// The comparison function for sorting the set by increasing order of its pair's
// second value. If the second value is equal, order by the pair's first value

struct compareByVal {
    bool operator()(std::pair<std::string, int>& a, std::pair<std::string, int>& b)
    {
        return a.second < b.second;
    }
};

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
    std::vector<int> vectOfSpaces;
    std::map<std::string, int> mapOfWords;
    // create an empty vector of pairs

    int space = 0;
    int max = 0;
    while (std::getline(file, str))
    {
        //strings.push_back(str);
        //std::cout << str << std::endl;
        for (int i = 0; i <= str.length(); i++)
        {
            if (str[i] == ' ') 
            {
                space++;
            }
        }
        int words = space +1;
        
        vectOfSpaces.push_back(words);

       
        //std::sort(vectOfSpaces.begin(), vectOfSpaces.end());
        mapOfWords.insert({ str, words });

        //std::cout << words << std::endl;
        //if (words > max)
        //{
        //    max = words;
        //}
        //auto it = std::max_element(vectOfSpaces.begin(), vectOfSpaces.end());

        space = 0;
        words = 0;
    }
    file.close();

    // print the vector
    //for (auto const& pair : vec) {
    //    std::cout << '{' << pair.first << "," << pair.second << '}' << std::endl;
    //}

    // create an empty vector of pairs
    //std::set<std::pair<std::string, int>, comp> set(mapOfWords.begin(), mapOfWords.end());

    std::map<std::string, int, compareByVal> mapOfWords;

    std::cout << mapOfWords.begin()->first << std::endl;

    //for (auto it = mapOfWords.cbegin(); it != mapOfWords.cend(); ++it)
    //{
    //    std::cout << it->first << " " << " " << it->second << "\n";
    //}
    /*for (auto [str, words] : mapOfWords)
    {

    }*/
    //std::cout << "Max wynosi: " << max << std::endl;

    //std::cout << "Wczytano " << strings.size() << " ³ancuchów";

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
