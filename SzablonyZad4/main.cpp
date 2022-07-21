/*
Zadanie 4.
Napisz klase StaticTable, kt�ra b�dzie mog�a przechowywa� N element�w dowolnego typu.
Napisz specjalizacj� dla wska�nik�w.
Napisz specjalizacj� dla N=0.

*/

#include <iostream>
#include "StaticTable.h"
#include <stdio.h>


int main()
{
    try
    {
        StaticTable<int, 10> table1;
        for (int i = 0; i < 10; ++i)
        {
            table1[i] = i;
        }
        table1.print(" ");
        table1.print("/");
        //for (int i = 0; i < 10; ++i)
        //{
        //    std::cout << "tab[" << i << "]= " << table1[i] << std::endl;
        //}

    }
    catch (std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }

    std::cout << std::endl;

    try
    {
        StaticTable<bool, 10>table2;

        table2[0] = true;
        std::cout << "tab[0] = " << table2[0] << std::endl;
    }
    catch (std::out_of_range& error)
    {
        std::cout << error.what() << std::endl;
    }
}

