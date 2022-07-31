
#include <iostream>


void helloWorld()
{
    std::cout << "Hello World!" << std::endl;
}

int addNum(int a, int b)
{
    return a + b;
}

int main()
{
    auto hello = []() {std::cout << "Hello World!" << std::endl; };
    auto add = [](int a, int b) {return a + b; };

    hello();
    int sum = add(4, 6);
    std::cout << sum;

    //int muzyka();
    //int (*dj)();
    //dj = &muzyka;

    //double dzielenie(int, int);
    //double (*ddd)(int,int);
    //ddd = &dzielenie;

    //double funkcyjka(int, char);
    //double (*nazwa_wskaznika)(int, char);
    //nazwa_wskaznika = &funkcyjka;


    //void* dosth(char tab[]);
    //void* (*ptr_dosth)(char tab[]);
    //ptr_dosth = &dosth;

    //bool funtion(bool (*fun2)(double, double) , char (*fun3)(double));
    //bool (*fun2)(double, double);

    //int funA();
    //int funB();
    //int funC();

    //int F();
    //int (*ptr_funA)();
    //ptr_funA = &F;

}

