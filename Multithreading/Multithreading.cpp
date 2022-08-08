// Multithreading.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <thread>

void print(int id, int howMany)
{
    for (int i = 0; i < howMany; ++i)
    {
        std::cout << "[id:" << id << "]says: " << howMany << std::endl;
    }
}

int main()
{
    //funkcje dzieja sie na osobnym watku
    std::thread thread1(print, 1, 20); // przyjmuje funkcje z parametrami
    std::cout << "thread1 wystartowany" << std::endl;

    std::thread thread2(print, 2, 20); // przyjmuje funkcje z parametrami
    std::cout << "thread2 wystartowany" << std::endl;

    thread1.join();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
