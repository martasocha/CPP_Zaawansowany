/*
Zad 6.
Napisz prosty s³ownik który przet³umaczy s³owo z jêzyka angielskiego na polski korzystajj¹c z mapy (kilka testowych s³ów).
*/
#include <iostream>
#include<map>

void translate(std::map < std::string, std::string> translator, const std::string& english)
{
    std::string polish{};
    try
    {
        polish = translator.at(english);
    }
    catch(const std::out_of_range& ex) // wyjatki lapiemy przez refencje do stalej
    {
        polish = "ERRPR: not found";
    }
    std::cout << english << " means: " << polish << std::endl;
}

int main()
{
    std::map < std::string, std::string> translator;

    translator.insert(std::pair< std::string, std::string>("hello", "czesc"));
    translator.insert({ "small", "maly" }); // pierwszy paramatr jest kluczem iw mozemy wyszuiwac tylko w jedna strone wartosci po kluczu
    translator.insert({ "big", "duzy" });
    translator.insert({ "goodbye", "do widzenia" });
    translator.insert({ { "goodbye", "do widzenia" } , { "coffee", "kawa" }, { "bed", "lozko" } });


    std::cout << translator.at("big") << std::endl;
    std::cout << translator["small"] << std::endl;
    //std::cout << translator.at("bat") << std::endl;
    translate(translator, "big");
    translate(translator, "goodbye");
    translate(translator, "bat");
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
