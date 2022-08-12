// 1. Napisz funkcjê, która przyjmuje stringa, nastêpnie uszereguje wszystkie litery w porz¹dku alfabetycznym i zwraca tak odwróconego stringa (sort).
// 2. Napisz analogiczn¹ funkcjê, która zwróci przemieszanego stringa (random_shuffle). Zwróæ uwagê czy za ka¿dym uruchomieniem, faktycznie string jest przemieszany innaczej
// 3. Napisz funkcjê, która przyjmuje dwa stringi a nastêpnie zwraca vector ich wspólnych liter (powtarzajcych sie w obu stringach).
// 4. Napisz funkcjê, która usunie spacje z podanego stringa.(remove i erase)
// 5. Napisz funkcjê, która zliczy wyst¹pienia podanej litery w podanym stringu (count).
// 6. Napisz funkcjê, która sprawdzi czy podany string jest palindromem(reverse i transform lub equal)
// 7. Napisz funkcjê, która stworzy wektor przechowuj¹cy potêgi kwadratowe z podanego zakresu np od. 3 do 10 (for_each)
// 8. Zmieñ poprzednie zadanie tak aby zwraca³o sumê kwadratów (accumulate)
// 9. Napisz funkcjê, która stworzy wektor przechowuj¹cy liczby od 1 do n. Nastêpnie utwórz dwa wektory. Jeden, którzy bêdzie przechowywa³ tylko wielokrotnoœci 2, a drugi 
// tylko wielokrotnoœci 3. Nastêpnie zwróæ vector przechowuj¹cy tylko wielokrotnoœci 2 i 3. (remove_copy_if, set_intersection)
// 10. Napisz funkcjê, która zwróci wszystkie mo¿liwe permutacje 3 liczb(next_permutation)
// 11. Napisz funkcjê, która przyjmuje wektor cyfr, a zwraca liczbê permutacji tych cyfr, które s¹ wielokrotnoœci¹ 11.
// 12. Napisz funkcjê, która zamieni podanego int na vector jej cyfr.
// 13. Napisz funkcjê, która znajdzie pierwsz¹ wiêksz¹ liczbê, która jest palindromem od zadanej liczby.

#include <iostream>
#include <algorithm>
#include <string>
#include <list>
#include <vector>
#include <cmath>
#include <numeric>

std::string sortAlphabetically(std::string str)
{
    std::sort(str.begin(), str.end());
    return str;
}

std::string mixedUpString(std::string str)
{
    std::random_shuffle(str.begin(), str.end());
    return str;
}

std::vector<char> findCommonLetters(std::string str1, std::string str2)
{
    std::vector<char> vect;

    for (unsigned int i = 0; i < str1.length(); ++i)
    {
        for (unsigned int j = 0; j < str2.length(); ++j)
        {
            if (str1.at(i) == str2.at(j))
            {
                vect.push_back(str1.at(i));
            }
        }
    }
    return vect;
}

std::string removeSpacesAndCountSize(std::string text)
{
    auto noSpaceEnd = std::remove(text.begin(), text.end(), ' ');
    text.erase(noSpaceEnd, text.end());

    return text;
}

std::string changeUppercaseToLowercase(std::string text)
{
    std::transform(text.cbegin(), text.cend(),
        text.begin(), // write to the same location
        [](unsigned char c) { return std::tolower(c); });
    return text;
}

int countHowManyLetters(std::string text, char letter)
{
    char character = std::tolower(letter);
    std::string textWithSmallLetters = changeUppercaseToLowercase(text);
    
    int n = std::count_if(textWithSmallLetters.begin(), textWithSmallLetters.end(), [letter](char n) {return n == letter; });
    return n;
}

bool isStringAPalindrome(std::string text)
{
    std::string changedText = removeSpacesAndCountSize(changeUppercaseToLowercase(text));
    std::string temp = changedText;
    std::reverse(changedText.begin(), changedText.end());
    
    return (changedText == temp);
}

std::vector<int> powersOfNum(int begin, int end)
{
    std::vector<int> vectOfNum;
    for (unsigned int i = 0; i < (end - begin + 1); ++i)
    {
        vectOfNum.push_back(begin + i);
    }
    std::for_each(vectOfNum.begin(), vectOfNum.end(),
        []( int& n) { n= pow(n,2); });
    return vectOfNum;
}

int sumOfPowers(int begin, int end)
{
    std::vector<int> vectOfNum = powersOfNum(begin, end);

    int sum = std::accumulate(vectOfNum.begin(), vectOfNum.end(), 0);
    return sum;
}

bool isIndivisibleBy2(int i) 
{ 
    return ((i % 2) != 0); 
}

bool isIndivisibleBy3(int i)
{
    return ((i % 3) != 0);
}

std::vector<int> findMultipliesOf2and3(int n)
{
    std::vector<int> v1;
    for (unsigned int i = 1; i <= n; ++i)
    {
        v1.push_back(i);
    }

    std::vector<int> v2 = v1;

    std::vector<int> vDivBy2(n);
    std::remove_copy_if(v1.begin(), v1.end(), vDivBy2.begin(), isIndivisibleBy2);
    auto vBy2 = std::remove(vDivBy2.begin(), vDivBy2.end(), 0);
    vDivBy2.erase(vBy2, vDivBy2.end());


    std::vector<int> vDivBy3(n);
    std::remove_copy_if(v2.begin(), v2.end(), vDivBy3.begin(), isIndivisibleBy3);
    auto vBy3 = std::remove(vDivBy3.begin(), vDivBy3.end(), 0);
    vDivBy3.erase(vBy3, vDivBy3.end());


    std::vector<int> vIntersection;

    std::set_intersection(vDivBy2.begin(), vDivBy2.end(),
        vDivBy3.begin(), vDivBy3.end(),
        std::back_inserter(vIntersection));

    return vIntersection;
}

void showAllPermutations(int a, int b, int c)
{
    std::vector<int> vect;
    vect.push_back(a);
    vect.push_back(b);
    vect.push_back(c);

    std::sort(vect.begin(), vect.end());
    do {
        for (const int& n : vect)
        {
            std::cout << n << " ";
        }
        std::cout << std::endl;
    } while (std::next_permutation(vect.begin(), vect.end()));

}

bool isIndivisibleBy11(int i)
{
    return ((i % 11) != 0);
}


int countPermutationsOfVect()
{
    std::cout << "Ile liczb chcesz przechowac w wektorze: ";
    int n;
    std::cin >> n;

    std::vector<int> vect;
    int count = 0;
    while (count != n)
    {
        std::cout << "Podaj " << count << " liczbe: ";
        int number;
        std::cin >> number;
        vect.push_back(number);
        count++;
    }

    std::vector<int> vectCopy(n);
    std::remove_copy_if(vect.begin(), vect.end(), vectCopy.begin(), isIndivisibleBy11);
    auto vDivBy11 = std::remove(vectCopy.begin(), vectCopy.end(), 0);
    vectCopy.erase(vDivBy11, vectCopy.end());


    int numOfPerm = 0;
    std::sort(vectCopy.begin(), vectCopy.end());
    do {
        for (const int& n : vectCopy)
        {
            std::cout << n << " ";
        }
        numOfPerm++;
        std::cout << std::endl;
    } while (std::next_permutation(vectCopy.begin(), vectCopy.end()));

    return numOfPerm;
}

std::vector<int> changeNumToVect(int n)
{
    std::vector<int> vect;
    do
    {
        vect.push_back(n % 10);
        n = n / 10;
    } while (n % 10 != 0);

    std::reverse(vect.begin(), vect.end());
    return vect;
}

std::vector<int> findBiggerPalindrom(int n)
{
    std::vector<int> vect = changeNumToVect(n);
    do
    {
        vect.push_back(n % 10);
        n = n / 10;
    } while (n % 10 != 0);

    return vect;
}

int main()
{
    //Zad 1
    std::cout << "Zad 1" << std::endl;
    std::string text = "stonoga";
    std::string sortText = sortAlphabetically(text);
    std::cout << sortText << std::endl;

    //Zad 2
    std::cout << "Zad 2" << std::endl;
    std::cout << mixedUpString(sortText) << std::endl;
    std::cout << mixedUpString(sortText) << std::endl;

    //Zad 3
    std::cout << "Zad 3" << std::endl;
    std::string text1 = "apghtuv";
    std::string text2 = "gtwqpoa";
    std::vector<char> commonLettersVector;
    commonLettersVector = findCommonLetters(text1, text2);
    for (char& n : commonLettersVector)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
   
    //Zad 4

    std::string newText = "Ala ma kota, a kot ma Ale";
    std::string textWithoutSpaces = removeSpacesAndCountSize(newText);
    for (char& n : textWithoutSpaces)
    {
        std::cout << n;
    }
    std::cout << std::endl;
    //Zad 5

    int num = countHowManyLetters(newText,'a');
    std::cout << "Ile razy powtarza sie litera: " << num << std::endl;
    
   //Zad 6
    std::string string = "Kobyla ma maly bok";
    std::cout << "Czy tekst: Kobyla ma maly bok, to palindrom: " << std::boolalpha << isStringAPalindrome(string) << std::endl;
    std::string string2 = "Ala ma kota, a kot ma ale";
    std::cout << "Czy tekst: Ala ma kota, a kot ma ale: " << std::boolalpha  <<  isStringAPalindrome(string2) << std::endl;

    //Zad 7
    std::vector<int> vectOfNums = powersOfNum(3, 10);
    for (int& n : vectOfNums)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;
    //Zad 8
    int sum = sumOfPowers(3, 10);
    std::cout << "Suma kwadratow liczb z zakresu 3 do 10 wynosi: " << sum << std::endl;

    //Zad 9
    std::vector<int> vectOfNums2 = findMultipliesOf2and3(30);
    for (int& n : vectOfNums2)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    //Zad 10
    int a = 10;
    int b = 8;
    int c = 4;
    showAllPermutations(a, b, c);

    //Zad 11
    std::cout << "Liczba permutacji dla cyfr ktore sa wielkrotnoscia 11 wynosi: " << countPermutationsOfVect() << std::endl;

   //Zad 12
    int number = 347892;
    std::vector<int> newVect = changeNumToVect(number);
    for (int& n : newVect)
    {
        std::cout << n << " ";
    }
    std::cout << std::endl;

    //Zad 13
    int number2 = 128892;
    std::vector<int> newVect2 = findBiggerPalindrom(number2);
    std::cout << "Palindrom tej liczby wynosi: ";
    for (int& n : newVect2)
    {
        std::cout << n;
    }
    std::cout << std::endl;
}

