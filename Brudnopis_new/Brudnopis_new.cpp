// Brudnopis_new.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <list>

int main()
{
    std::vector<int> numbers(100);
    //std::list<int> numbers(100);
    std::iota(numbers.begin(), numbers.end(),-80);


    auto it = std::remove(numbers.begin(), numbers.end(), 0); // remove zwraca pierwszy element do usuniecia (zwraca iterator), remove nadpisuje wszystkie elementy w przod i ostatnie elementy sa do usuniecia

    auto it2 = std::remove(numbers.begin(), numbers.end(), [](const int i) {return i < -30; }); // jesli chcemy usunac wszystkie mniejsze od - 30

    numbers.erase(it2, numbers.end()); // usun odtad do konca wektora

    //numbers.erase(std::remove(numbers.begin(), numbers.end(), 0), numbers.end());

    std::for_each(numbers.begin(), numbers.end(), [](const int i) {std::cout << i << ";\n"; });

    std::vector<int> second;
    //kopiuje pierwsze 10 wartosci


    std::copy_n(numbers.begin(), 10, std::back_inserter(second)); //w przypadku iteratora robi push back
    std::cout << std::endl << std::endl;

    auto second_inserter = std::back_inserter(second);
    second_inserter = 123;
    second_inserter = 29;


    std::for_each(second.begin(), second.end(), [](const int i) {std::cout << i << ";\n"; });

    //find zeby znalezc miejsce
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
