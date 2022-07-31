#include <iostream>
#include <regex>


bool checkPESEL(const std::string& pesel)
{
    std::regex peselRegex("\\d{11}"); // musimy dac podwojny znak, bo nastepny znak potraktuj doslownie
    return std::regex_match(pesel, peselRegex); // sprawdza caly string, search dany podciag
    std::regex peselRegex("^\\d{11}$"); 
    // ^ - dopasuj od poczatku stringa, 
    // \\d tylko cyfry
    // {] musi byc ich dokladnie 11
    // $ koniec stringa
    //return std::regex_search(pesel, peselRegex); // jak chcemy wyciac ze stringa cos co nas interesuje
}
// checkPesel zwraca prawde lub falsz czy pasuje czy nie pasuje

int main()
{
    std::string pesel1("12324598762");
    std::string pesel2("123245987");
    std::string pesel3("1232459823447");
    std::string definatelyNotPesel("123245987wwaaa");

    std::cout << pesel1 << "wynik: " << checkPESEL(pesel1) << std::endl;
    std::cout << pesel2 << "wynik: " << checkPESEL(pesel2) << std::endl;
    std::cout << pesel3 << "wynik: " << checkPESEL(pesel3) << std::endl;
    std::cout << definatelyNotPesel << "wynik: " << checkPESEL(definatelyNotPesel) << std::endl;
}

