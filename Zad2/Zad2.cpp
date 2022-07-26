// Zad2.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<list>

template<typename T>
void print(std::list<T>& list)
{
    for (size_t i = 0; i < list.size(); ++i)
    {
        std::cout << "[" << i << "]= " << list.at(i) << std::endl;
    }
}
int main()
{
	std::list<int>list1 = { 1,2,3,4,5,6,7,8,9,10 };
	std::list<int>list2{ 11,12,13,14,15,16,17,18,19,20 };

    for (auto it = list1.begin(); it != list1.end(); ++it) //auto = automatyczna dedukcja typu

        // tworze sobie iterator i przyspuje mu poczatek listy, tak dlugo go wypisuje jak dlugo bedzie rozny od end
    {
        std::cout << *it << "; ";
    }
    // wypisac liste 2 od konca do poczatku
    
    for (auto it = list2.rbegin(); it != list2.rend(); ++it)
    {
        std::cout << *it << "; ";
    }

    auto copyFrom = list1.begin();
    std::advance(copyFrom, 2);

    auto copyTo = list1.begin();
    std::advance(copyTo, 7);

    auto to = list2.begin(); //przesuam iterator w ktore miejsce chce skopiowac
    std::advance(to, 3);

    list2.splice(to, list1, copyTo, copyFrom); // na 3 pozycje przenies mi cala liste

    std::cout << std::endl << std::endl << std::endl;

    for (auto it = list2.begin(); it != list2.end(); ++it)
    {
        std::cout << *it << "; ";
    }

   // list2.splice(list2.begin(), list1, it, list1.end());
	//list2.splice(3, list1, 3, 7);

}

