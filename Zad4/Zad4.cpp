#include <iostream>
#include <map>


void printMap(std::map<char, int>& map)
{
	for (const auto& n : map) {
		std::cout << n.first << " = " << n.second << "; ";
	}
}

void checkLetters(std::map<char, int>& map, std::string text)
{
	for (size_t i = 0; i < text.size(); ++i)
	{
		if (text[i] == 'a')
		{
			map['a'] += 1;
		}
		else if (text[i] == 'l')
		{
			map['l'] += 1;
		}
		else if (text[i] == 'm')
		{
			map['m'] += 1;
		}
		else if (text[i] == 'k')
		{
			map['k'] += 1;
		}
		else if (text[i] == 'o')
		{
			map['o'] += 1;
		}
		else if (text[i] == 't')
		{
			map['t'] += 1;
		}

	}
}


int main()
{

	std::map<char, int> mapOfLetters{ {'a' ,0}, {'l' ,0}, {'m' ,0}, {'k' ,0}, {'o' ,0}, {'t' ,0} };

	std::string text = "ala ma kota";

	checkLetters(mapOfLetters, text);

	printMap(mapOfLetters);

}