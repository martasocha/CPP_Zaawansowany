#include <iostream>
#include <map>


void printMap(std::map<char, int>& map)
{
	  for (const auto& n : map) {
	      std::cout << n.first << " = " << n.second << "; ";
	  }
}


int main()
{

	std::map<char, int> mapOfLetters { {'a' ,0}, {'l' ,0}, {'m' ,0}, {'k' ,0}, {'o' ,0}, {'t' ,0}};

	std::string text = "ala ma kota";

	for (size_t i = 0; i < text.size(); ++i)
	{
		if (text[i] == 'a')
		{
			mapOfLetters['a'] += 1;
		}
		else if (text[i] == 'l')
		{
			mapOfLetters['l'] += 1;
		}
		else if (text[i] == 'm')
		{
			mapOfLetters['m'] += 1;
		}
		else if (text[i] == 'k')
		{
			mapOfLetters['k'] += 1;
		}
		else if (text[i] == 'o')
		{
			mapOfLetters['o'] += 1;
		}
		else if (text[i] == 't')
		{
			mapOfLetters['t'] += 1;
		}

	}

	printMap(mapOfLetters);

}