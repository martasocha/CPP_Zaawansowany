// Zad02.cpp : Stwórz wektor 100 kolejnych liczb ca³kowitych z zakresu od 1 do 100

#include <iostream>
#include <vector>
#include <algorithm>

class LessThen50
{
    int number;
public:
    LessThen50(int num) : number(num)
    {
    }
    bool operator() (int value) const {
        return value > number;
    }
};


void printAll(int num)
{
    std::cout << num << " ";
}

bool isBiggerThen4(int num)
{
    return (num > 4);
}

int main()
{
    std::vector<int> vect;
    
    for(int i = 1; i <= 100; ++i)
    {
        vect.push_back(i);
    }
    //a) Wypisz wszystkie liczby (for_each + unary function)
    std::for_each(vect.begin(), vect.end(), printAll);
    std::cout << std::endl;

    //b) Wypisz wszystkie liczby mniejsze od 50 (for_each + funktor)

    std::for_each(vect.begin(), vect.end(), LessThen50(50));

    //c) Nastêpnie policz ile jest liczb wiêkszych ni¿ 4 (count_if + predykat)
    int howMany = 0;

    howMany = count_if(vect.begin(), vect.end(), isBiggerThen4);
    std::cout << std::endl;
    std::cout << "Liczb wiekszych od 4 jest: " << howMany << std::endl;

    //a) dla lambdy
    std::for_each(vect.begin(), vect.end(), [](const int& n) { std::cout << " " << n; });
    std::cout << std::endl;

    //b) dla lambdy
    std::for_each(vect.begin(), vect.end(), [](const int& n) { if (n < 50) { std::cout << " " << n; } });
    std::cout << std::endl;

    //c) dla lambdy
    int howMany2 = 0;
    howMany2 = count_if(vect.begin(), vect.end(), [](int number) {return number > 4; });
    std::cout << std::endl;
    std::cout << "Liczb wiekszych od 4 jest: " << howMany2 << std::endl;
}

