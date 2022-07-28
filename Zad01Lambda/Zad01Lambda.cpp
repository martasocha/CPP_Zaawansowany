// Zad 0.1 Lambda
//Napisz zwyk�� funkcj� oraz lambd�(przypisz j� do zmiennej) Nast�pnie je wywo�aj :
//a) funkcj� wypisuj�ca �Hello World�
//b) Funkcja dodaj�ca dwie liczby do siebie(i zwracaj�ca j�)

#include <iostream>

void sayHello()
{
    std::cout << "Hello World!\n";
}

int add(int a, int b)
{
    return a + b;
}

int main()
{
    sayHello();
    auto printHello = [](){std::cout << "Hello World!\n"; };
    printHello();
    int a = 5;
    int b = 10;
    int sum = add(a, b);
    std::cout << sum << std::endl;

    auto addNum = [](int& x, int& y) {return x + y; };
    int sum2 = addNum(a,b);
    std::cout << sum2 << std::endl;
}
