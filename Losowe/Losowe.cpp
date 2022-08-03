// Losowe.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <random>
#include <algorithm>
#include <numeric>

int main() {

	std::vector<int> numbers;
	std::random_device r;
	std::default_random_engine defEngine(r()); // zasianie ziarna losowosci za pomoca r, odpowiada za faktyczne wtgenerowanie liczb losowych
	std::uniform_int_distribution<int> intDistro(0, 10);
	for (int i = 1; i <= 100; i++) {
		numbers.push_back(intDistro(defEngine));
	}
	for (const int n : numbers) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	auto howMany = count_if(numbers.cbegin(), numbers.cend(), [](int number) {return number == 5; });
	std::cout << "Ilosc wystapien liczby 5: " << howMany << std::endl;
	std::cout << std::endl;

	double average = std::accumulate(numbers.begin(), numbers.end(), 0.0) / numbers.size();
	std::cout << "Wartosc srednia: " << howMany << std::endl;
	std::cout << std::endl;



	std::cout << "Inny rozk³ad wartosci: "<< std::endl;
	std::vector<int> numbers2;
	std::default_random_engine defEngine2(r());
	std::normal_distribution<> dis(5,1);
	for (int i = 1; i <= 100; i++) {
		numbers2.push_back(static_cast<int>(dis(defEngine2)));
	}
	for (const int n : numbers2) {
		std::cout << n << " ";
	}
	std::cout << std::endl;

	auto howMany2 = count_if(numbers2.cbegin(), numbers2.cend(), [](int number) {return number == 5; });
	std::cout << "Ilosc wystapien liczby 5: " << howMany2 << std::endl;
	std::cout << std::endl;

	double average2 = std::accumulate(numbers2.begin(), numbers2.end(), 0.0) / numbers2.size();
	std::cout << "Wartosc srednia: " << average2 << std::endl;
	std::cout << std::endl;
}