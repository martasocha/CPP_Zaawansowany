// BrudnopisMapa.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include<map>


void printMap(std::map<char, int>& map)
{
	for (const auto& n : map) {
		//if (n.second != 0)
		//{
			std::cout << n.first << " = " << n.second << "; ";
		//}
	}
}
int main()
{
	std::map<char, int> mapOfLetters{ {'a' ,0}, {'b' ,0}, {'c' ,0}, {'d' ,0}, {'e' ,0}, {'f' ,0}, {'g' ,0}, {'h' ,0}, {'i' ,0}, {'b' ,0}, {'b' ,0}, {'l' ,0}, {'m' ,0}, {'k' ,0}, {'o' ,0}, {'t' ,0} };
	printMap(mapOfLetters);
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
