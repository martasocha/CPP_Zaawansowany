#include <iostream>
#include <iomanip>




template<typename T>
void print(T s)
{
    std::cout << s << std::endl;
}

template<typename T1, typename T2> // szablon z 2 argumentami
void print(T1 s, T2 p) // szablon funkcji print
{
    std::cout << s << " " << p << std::endl;
}

template<typename T1, typename T2>
void print(T1* s, T2* p) // szablon funkcji print
{
    std::cout << *s << " " << *p << std::endl;
}

template<typename T1>
void print(T1 s, bool p) // szablon funkcji print
{
    std::cout << s << ", " << (p ? "true": "false") << std::endl;
}

// praca domowa: Szablon gdzie bool jest na 1 miejscu, a na drugim dowolny argyment

template<> // specjalizacja szablonu dla typu double
void print(double s)
{
    std::cout << std::setprecision(2) << std::endl; // dla double ograniczy do dwoch miejsc po przecinku
}


template<> // specjalizacja szablonu dla typu bool
void print(bool check)
{
    if (check)
    {
        std::cout << "prawda" << std::endl;
    }
    else
    {
        std::cout << "falsz" << std::endl;
    }
}

template<int N>
void printKu()
{
    for (int i = 0; i < N; ++i)
        std::cout << "Ku";
}

template<typename T1>
class A
{
    T1 fieldA;
    T1 funA();
};

template<typename T1>
class B : A<T1>
{
    T1 fieldB;
    void funB(T1 a, T1 b);
};

class C : A<int> // nie jest szablonem // jak dam inta to wk³ada mi w miejsce T1 same inty, wszêdzie w argumenty i funkcje
{

};

template<typename T1>
class D : A<float>
{

};

template<typename T1, typename T2>
class D : A<float>
{

};

template<typename T1, typename T2>
class E : A<T2>
{
   T1 fieldE
};

class F
{
    int fieldF;

    template<typename T>
    void funF(T p); // klasa ma w sobie funkje ktora jest szablonem
};

//struct D
//{
//private:
//    int z;
//};

int main()
{
    int i = 1;
    double d = 123.2143;
    bool b = true;

    print(i);
    print(d);
    print(b);
    printKu<100>();
    std::cout << std::endl;
    print(3.21, true);
    //print(false, 3.33);
    //D obj;
    //print obj;

    A<int> objA1;
    A<bool> objA2;
    A<std::string> objA3;
    E<double, bool> objE;
    D<F> objD;
}
