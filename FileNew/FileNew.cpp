// FileNew.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <random>
#include <fstream>
#include <iostream>
#include <algorithm>

void saveVectorToFile(const std::vector<int&> vec, std::string& fileName)
{
    std::ofstream file(fileName, std::ios::out | std::ios::app);

    if (file.is_open())
    {
        std::cout << "Plik zostal otwarty: " << fileName << std::endl << std::endl;

        for (auto& el : vec)
        {
            file << el << '\n';
        }

        file.close();
    }
}

void loadFromFile(const std::string& fileName)
{
    std::vector<int> nums;
    std::ifstream file(fileName);
    
    if (file.is_open())
    {
        std::cout << "Plik zosta otwart: " << fileName << std::endl << std::endl;

        while (file.good() && !file.eof())
        {
            int val;
            file >> val;
            nums.push_back(val);
        }
        file.close();
    }

}

int main()
{
    std::random_device ranDev; //urzadzenie sluzace do generowania ziarna (seed)
    std::default_random_engine randomEngine(ranDev()); // silni zwracajacy faktycznie losowe liczny, ziarno przekazane do c-tora daje nam to ze mozemy
    //std::uniform_real_distribution<double> realDist(-10000.0, 10000.0);
    std::uniform_int_distribution<int> intDist(-100000, 100000);

    std::cout << intDist(randomEngine);

    //std::vector<int> nums(100000); // wektor 100000 elementow, kazdy =0

    const size_t howManyNumbers = 100000;
    std::vector<int> nums;
    nums.reserve(howManyNumbers);

    for (int i = 0; i < howManyNumbers; ++i)
    {
        nums.push_back(intDist(randomEngine));
    }

    const std::string fileName = "wylosowaneLiczby.txt";
    

    auto it = nums.begin();
    std::advance(it, 100);

    std::for_each(nums_begin(), it, [](int& n) {std::cout << n << '\n'; });
}

