

#include <iostream>
#include <vector>


template<typename T>
void bubbleSort(std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size() - 1; ++i) //size_t to unsigned long long, do rozmiaru wektorów u¿ywami size_t
    {
        for (size_t j = 0; j < vec.size() - 1; ++j)
        {
            if (vec.at(j) > vec.at(j + 1)) // at bardziej porzadane bo rzuca wyjatek czy nie wychodzimy poza zakres
            {
                //T tmp = vec.at(j);
                //vec.at(j) = vec.at(j + 1);
                //vec.at(j + 1) = tmp;
                std::swap(vec.at(j), vec.at(j + 1));
            }
        }
    }

}

template<typename T>
void printVector(std::vector<T>& vec)
{
    for (size_t i = 0; i < vec.size(); ++i)
    {
        std::cout << "[" << i << "]= " << vec.at(i) << std::endl;
    }
}


int main()
{
    std::vector<int>vect;
     //utworz funkcje szablonowa, ktora wczyta dowolny typ
    int value;
    do
    {
        std::cout << "Podaj liczbe: ";
        std::cin >> value;
        vect.push_back(value);

    } while (value != 0);

    for (unsigned int i = 0; i < vect.size(); ++i)
    {
        std::cout << vect[i] << " ";
    }

    std::cout << std::endl;

    int sum = 0;
    for (unsigned int i = 0; i < vect.size(); ++i)
    {
        sum += vect[i];
    }
    std::cout << "Suma wynosi= " << sum << std::endl;
   
    std::cout << "Po sortowaniu= " << std::endl;
    bubbleSort<int>(vect);
    printVector<int>(vect);

    // do zamiany elementu kopia elementu tymczasowego
}
