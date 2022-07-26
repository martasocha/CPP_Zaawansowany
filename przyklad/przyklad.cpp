// przyklad.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int unsafe()
    {
        A* a = new A;

        if (a->f())
        {
            B* b;
            try
            {
                b = new B;
            }
            if (b->f())
            {
                //zakladamy ze wszystkie metody zwracaja inta
                int ret = b->g();
                delete b;
                delete a;
                return ret;
            }
            else
            {
                int ret = a->g()
                delete b;
                delete a;
                return ret;
            }
        }
        delete a;
        return 0;
    }
}