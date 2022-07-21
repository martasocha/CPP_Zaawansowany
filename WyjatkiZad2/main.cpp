#include <iostream>
#include "PostiveNumber.hpp"

int main()
{
    //double a = 0;
    //float b = 0;
    //int c = 0;
    //double d = 0;

    //std::cout << "Podaj liczbe typu double: ";
    //std::cin >> a;
    //std::cout << "Podaj liczbe typu float: ";
    //std::cin >> b;
    //std::cout << "Podaj liczbe typu int: ";
    //std::cin >> c;


            //PositiveNumber num1(a);
            //PositiveNumber num2(b);
            //int num = 10;
            //PositiveNumber num3 = num1 + num;

            ////std::cout << "Podane liczby to" << num1.getValue() << " " << num2.getValue() << " " << num3.getValue() << std::endl;

            //try
            //{
            //std::cout << "Podaj liczbe ktora chcesz dodac: ";
            //std::cin >> d;
            //num1.add(d);
            //std::cout << "wynik wynosi: " << num1.getValue() << std::endl;

            //std::cout << "Podaj liczbe ktora chcesz odjac: ";
            //std::cin >> d;
            //num1.substract(d);
            //std::cout << "wynik wynosi: " << num1.getValue() << std::endl;

            //}
            //catch (std::string& error)
            //{
            //    std::cout << error << std::endl;
            //}

            PositiveNumber a; // zmienne lepiej deklarowac poza try catch, a w srodku try- catch tylko te ktore rzucaja wyjatkami
            //konstruktory nie powinny rzucac wyjatkami

            try
            {
                a.setValue(100);

                for (int i = 15; i >= 0; --i)
                {
                    a.substract(10);
                    std::cout << a.getValue() << std::endl;
                }
                std::cout << "Poza petla";
            }
            catch (std::out_of_range& error)
            {
                std::cout << error.what() << std::endl; // funkcja what zwaraca
            }
            catch (std::bad_alloc& error)
            {
                std::cout << error.what() << std::endl; // funkcja what zwaraca
            }
            catch (std::exception& ex)
            {
                std::cout << "Unexpected exception cought: " << ex.what() << std::endl; // funkcja what zwaraca
            }
            catch (...) //³apie ka¿dy obiekt rzucony, raczej nie powinnismy z tego korzystac
            {
                //nic nie mozna zrobic
            }

            // nalezy zaimplementowac funkce what

}