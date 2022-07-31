// Time.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <chrono>
#include <iomanip>

long fibonacci(unsigned n)
{
    if (n < 2) return n;
    return fibonacci(n - 1) + fibonacci(n - 2);
}

int main()
{
   /* const auto now = std::chrono::system_clock::now();
    const auto t_c = std::chrono::system_clock::to_time_t(now);
    std::cout << std::put_time(std::localtime(&t_c), "%F %T.\n");*/

    auto start = std::chrono::steady_clock::now(); //punkt startowy, pobiera aktualny time_point
    std::cout << "fib(42) = " << fibonacci(42) << std::endl;
    auto end = std::chrono::steady_clock::now(); // drugi timepoint

    auto howLong = std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() / 1000.0;
    std::cout << "Wyliczenie tego zajelo: " << howLong << "s" << std::endl;
}

