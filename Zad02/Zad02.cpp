// Zad02.cpp : Stwórz wektor 100 kolejnych liczb ca³kowitych z zakresu od 1 do 100

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>

class LessThen
{
    int _bound;
public:
    LessThen(int value) : _bound(value)
    {
    }
    void operator() (int value) const {
        if (value < _bound)
        {
            std::cout << value << " ";
        }
    }
};


//struct LessThen50
//{
//    void operator() (int value)
//    {
//        if (value < 50)
//        {
//            std::cout << value << " ";
//        }
//    }
//};

void printAll(const int num)
{
    std::cout << num << " ";
}

bool isBiggerThan4(const int num)
{
    return (num > 4);
}

int main()
{
    std::vector<int> vect(100);
    
    //std::vector<int> vect;
    //for(int i = 1; i <= 100; ++i)
    //{
    //    vect.push_back(i);
    //}
    std::iota(vect.begin(), vect.end(), 1);

    //a) Wypisz wszystkie liczby (for_each + unary function)
    std::cout << "a) Wypisz wszystkie liczby(for_each + unary function)" << std::endl;
    std::for_each(vect.begin(), vect.end(), printAll);
    std::cout << std::endl;
    std::cout << std::endl;

    //b) Wypisz wszystkie liczby mniejsze od 50 (for_each + funktor)
    std::cout << "b) Wypisz wszystkie liczby mniejsze od 50 (for_each + funktor)" << std::endl;
    std::for_each(vect.begin(), vect.end(), LessThen(50));
    std::cout << std::endl;
    std::cout << std::endl;

    //c) Nastêpnie policz ile jest liczb wiêkszych ni¿ 4 (count_if + predykat)
    std::cout << "c) Policz ile jest liczb wiêkszych ni¿ 4 (count_if + predykat)" << std::endl;
    int howMany = 0;

    howMany = count_if(vect.begin(), vect.end(), isBiggerThan4);
    std::cout << "Liczb wiekszych od 4 jest: " << howMany << std::endl;
    std::cout << std::endl;

    //a) dla lambdy
    std::cout << "a) dla lambdy" << std::endl;
    std::for_each(vect.begin(), vect.end(), [](const int& n) { std::cout << " " << n; });
    std::cout << std::endl;
    std::cout << std::endl;

    //b) dla lambdy
    std::cout << "b) dla lambdy" << std::endl;
    std::for_each(vect.begin(), vect.end(), [](const int& n) { if (n < 50) { std::cout << " " << n; } });
    std::cout << std::endl;
    std::cout << std::endl;

    //c) dla lambdy
    std::cout << "c) dla lambdy" << std::endl;
    int howMany2 = 0;
    howMany2 = count_if(vect.cbegin(), vect.cend(), [](int number) {return number > 4; }); //cbegin, cend iterator pozwalajacy na odczyt
    std::cout << std::endl;
    std::cout << "Liczb wiekszych od 4 jest: " << howMany2 << std::endl;
    std::cout << std::endl;

    // e) w zale¿noœci od zmiennej lokalnej dzielnik wypisz wszystkie liczby podzielne przez niego(for_each + lambda
    std::cout << "e) w zaleznosci od zmiennej lokalnej dzielnik wypisz wszystkie liczby podzielne przez niego(for_each + lambda)" << std::endl;
    int value = 2;
    auto divByValue = [&value](int& n)
    {
        if ((n % value) == 0)
        {
            std::cout << " " << n;
        }
    };
    std::for_each(vect.begin(), vect.end(), divByValue);
    std::cout << std::endl;
    std::cout << std::endl;

    //f) Zlicz sumê wszystkich liczb parzystych i zapisz j¹ do zmiennej lokalnej int sum;
    std::cout << "f) Zlicz sumê wszystkich liczb parzystych i zapisz ja do zmiennej lokalnej int sum" << std::endl;
    int sum = 0;
    int value2 = 3;
    std::for_each(vect.begin(), vect.end(), [&sum](int i) {
        if (i % 2 == 0)
            sum+=i; });
    std::cout << "Suma wynosi: " << sum << std::endl;
    auto sumOdd = [](int a, int b) {
        if (b % 2 == 0) 
            return a + b; };
    int result = std::accumulate(vect.cbegin(), vect.cend(), 0, sumOdd);
    std::cout << "Result = " << result << std::endl;

}

