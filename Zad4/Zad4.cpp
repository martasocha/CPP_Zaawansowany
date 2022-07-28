#include <iostream>
#include <map>


void printMap(std::map<char, int>& map)
{
	for (const auto& n : map) {
		if (n.second != 0 && n.first != ' ')
		{
			std::cout << n.first << " = " << n.second << "; ";
		}
	}
}

void checkLetters(std::map<char, int>& map, std::string text)
{

	for (size_t i = 0; i < text.size(); ++i) // dotyczylo intow
	{
		map[text[i]]++;
	}
}


int main()
{

	std::map<char, int> mapOfLetters;
	std::string text = "ala ma kota";
	std::string text2 = "a kot ma ale";

	checkLetters(mapOfLetters, text2);
	printMap(mapOfLetters);

	std::cout << std::endl;
	checkLetters(mapOfLetters, text2);
	printMap(mapOfLetters);

}