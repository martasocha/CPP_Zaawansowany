#include <iostream>

//klasa ktora wyglada jak funkcja

//Struktora lub klasa ktorej obiekty zachowuja sie jak funkcja

struct HelloWorld
{
    void operator()(/*Insert args here*/)
    {
        std::cout << "Hello World!\n";
    }
};

int main()
{
    HelloWorld(); // nic sie nie wywolalo bo to jest konstruktor
    HelloWorld hello;
    hello(); //obiekt zachowuje sie jak funkca
}

