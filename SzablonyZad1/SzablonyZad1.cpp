#include <iostream>
#include <stdio.h>

template<typename T>
T max(T a, T b) // szablon
{
    if (a > b)
    {
        return a;
    }
    else
    {
        return b;
    }
    //return a > b ? a : b; // operatr potrójny (ternary) a > b- porownanie a po ? typ zwracany a, lub typ zwracany b
}

template<typename T> // trzeba wyspecjalizowac dla wskaznika // specjalizacja czêœciowa
T* max(T* a, T* b)
{
    return *a > *b ? a : b;
}

template<> // specjalizacja pe³na
char* max(char* a, char* b)
{
    if (strcmp(a, b) > 0)
    {
        return a;
    }
    else
    {
        return b;
    }
}

//mo¿emy parametryzowaæ typem lub argumentem

template<typename T>
T max(T* data, const unsigned int n) // przeci¹¿anie szablonu, inny szablon ni¿ ten pierwszy
{
    T max = data[0];
    for (unsigned int i = 0; i < n; ++i)
    {
       if (data[i] > max)
       {
           max = data[i];
       }
    }
    return max;
}



int main()
{
    int value1 = 10;
    int value2 = 8;
    std::cout << "Wieksza int: " << max(value1, value2) << std::endl;
    std::cout << "Wieksza double: " << max(4.56, 90.87) << std::endl;

    int* ptr1 = &value1;
    int* ptr2 = &value2;
    std::cout << "Wieksza double: " << *max(ptr1,ptr2) << std::endl;

    std::cout << "Wiekszy lancuch: " << max("AAaaaaaa", "Bbb") << std::endl; //nie trzeba * cut potrafi wypisac tablice znakow

    const unsigned int size = 10;
    double tab[size] = { 0.0, 0.01, 2.33, 4, 5, 7, 34.099, 90, 199, 23 };
    std::cout << "Najwiekszy element w tablicy: " << max(tab, size) << std::endl;
}
