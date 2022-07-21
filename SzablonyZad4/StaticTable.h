/*
Zadanie 4.
Napisz klase StaticTable, która bêdzie mog³a przechowywaæ N elementów dowolnego typu.
Napisz specjalizacjê dla wskaŸników.
Napisz specjalizacjê dla N=0.

*/

#pragma once
#include <stdexcept>


template<typename T, unsigned int N>
class StaticTable
{
public:
    T& operator[](const unsigned int i) // szablon musi byc zadeklarowany w miejscu wystapienia
    {
        if (i >= N)
        {
            throw std::out_of_range("Wychodzisz poza tablice");
        }
        else
        {
            return tab[i];
        }
    }


    template<typename T2>
    void print(T2 separator)
    {
        //wypisuje cala tablice u¿ywaj¹c zmiennej T2 separator jako znaku rozdzielaj¹cego wartoœci
        for (int i = 0; i < N; ++i)
        {
            std::cout << tab[i] << separator;
        }
        std::cout << std::endl;
    }

private:
    T tab[N];
};


template<unsigned int N>
class StaticTable<bool,N>
{
public:
    bool& operator[](const unsigned int i) // szablon musi byc zadeklarowany w miejscu wystapienia
    {
        if (i >= N)
        {
            throw std::out_of_range("Wychodzisz poza tablice");
        }
        else
        {
            return tab[i];
        }
    }

private:
    bool tab[N];
};