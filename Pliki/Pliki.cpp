// Pliki.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <random>
#include <algorithm>
#include <numeric>
#include <string>
#include <iterator>
#include <vector>

void printAll(const int num)
{
	std::cout << num << " ";
}


int main()
{
	std::vector<int> numbers;
	std::random_device randomDevice;
	std::default_random_engine defaultEngine(randomDevice());
	std::uniform_int_distribution<int> intDistribution(-100000, 100000);

	for (int i = 0; i <= 100000; ++i)
	{
		numbers.push_back(intDistribution(defaultEngine));
	}


	std::string fileName("C:\\Users\\mkandyba.MPD1\\source\\repos\\CPP_Zaawansowany\\Pliki\\Pliki2.txt");
	std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);
		
	if (fileToWrite.is_open())
	{
		for (int i = 0; i <= 100000; ++i)
		{
			if (fileToWrite.good())
			{
				fileToWrite << numbers[i] << "\n";
			}
		}
		fileToWrite.close();
	}
	else
	{
		std::cout << "Nie moge otworzyc pliku do zapisu";
		return -1;
	}



	std::string fileName2("Pliki2.txt");
	std::ifstream file(fileName2);

	if (file.is_open())
	{
		std::cout << "Plik zosta³ wczytany " << fileName << std::endl << std::endl;
	}
	else
	{
		std::cout << "Nie mogê otworzyæ pliku :(";
		return -1;
	}
	std::vector<int> vect;
	while (file.good() && !file.eof())
	{
		int temp;
		file >> temp;
		vect.push_back(temp);
	}
	file.close();


	auto vi = vect.begin();
	int i = 0;
	while (i != 100)
	{
		std::advance(vi, i);
		std::cout << *vi << std::endl;
		i++;
	}
}
