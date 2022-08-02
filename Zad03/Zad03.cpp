// Zad03.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main()
{
    //Utwórz wektor liczb ca³kowitych od -100 do 100.
    std::vector<int> vect;
    for (int i = -100; i <= 100; ++i)
    {
        vect.push_back(i);
    }
    for_each(vect.begin(), vect.end(), [](int& n) {std::cout << n << " "; });
    std::cout << std::endl;

    //a) Nastêpnie sprawdŸ czy wszystkie liczby s¹ dodatnie.
    if (std::all_of(vect.begin(), vect.end(), [](int i) {  return i>0; })) {
        std::cout << "Nie wszystkie liczby sa dodatnie\n";
    }
    std::cout << std::endl;
    //b) Czy istnieje jakakolwiek liczba podzielna przez 3, 5 i 30.
    
    std::cout << "Liczby podzielne przez 3, 5 i 30: ";
    auto divBy3530 = [](int& n) {
        if ((n % 3) == 0 && (n % 5) == 0 && (n % 30) == 0)
        {
            std::cout << n << ", ";
        }
    };

    std::for_each(vect.begin(), vect.end(), divBy3530);
    std::cout << std::endl;

    //c) Usuñ z kontenera 0.

    //auto it = std::remove(vect.begin(), vect.end(), [](const int& n) { return n < 0; });
    //vect.erase(it, vect.end());

    auto it2 = std::remove(vect.begin(), vect.end(), 0);

    vect.erase(it2, vect.end());

    for_each(vect.begin(), vect.end(), [](int& n) {std::cout << n << " "; });
    std::cout << std::endl << std::endl;
    //d) Nastêpnie sprawdŸ czy kontener nie zawiera wartoœci 0.
    auto result = std::find(vect.begin(), vect.end(), 0);

    (result != vect.end()) ? std::cout << "Wektor zawiera 0" << std::endl :
    (result != vect.end())
        ? std::cout << "wektor zawiera 0"
        : std::cout << "wektor nie zawiera 0";
    std::cout << std::endl << std::endl;
    //e) SprawdŸ czy kontener jest posortowany

    std::cout << "Czy wektor jest posortowany: " << std::boolalpha << std::is_sorted(vect.begin(), vect.end());
    std::cout << std::endl << std::endl;

    //f) Skopiuj do drugiego wektora wszystkie liczby wiêksze od 90 i mniejsze od -90

    std::vector <int> secondVect;

    std::copy_if(vect.begin(), vect.end(),
        std::back_inserter(secondVect),
        [](int n) { return n > 90 || n < -90; });
    for (int n : secondVect)
        std::cout << n << ' ';
    std::cout << std::endl;

    //g) Skopiuj do innego wektora 10 kolejnych liczb zaczynaj¹c od 78
    std::cout << std::endl << std::endl;
    std::vector<int> thirdVect;

    for_each(vect.begin(), vect.end(), [](int& n) {std::cout << n << " "; });
    std::cout << std::endl;
    std::cout << std::endl << std::endl;

    auto it = find(vect.begin(), vect.end(), 78);
    auto itEnd = find(vect.begin(), vect.end(), 78) + 10;

    std::copy(it, itEnd, std::back_inserter(thirdVect));
    for (int n : thirdVect)
        std::cout << n << ' ';
    std::cout << std::endl;
}

