// RegexEmail.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <regex>

bool checkEmail(const std::string& email)
{
    std::regex emailRegex("[a-z0-9._]{3,}@[a-z0-9_]+.(com|pl|edu)$"); // musimy dac podwojny znak, bo nastepny znak potraktuj doslownie
    return std::regex_match(email, emailRegex); // sprawdza caly string, search dany podciag
}

std::string readEmail()
{
    std::cout << "Podaj adres e-mail:";
    std::string email;
    std::cin >> email;
    return email;
}

int main()
{

    std::string mail = readEmail();
    std::cout << "Czy adres email jest poprawny : " << checkEmail(mail) << std::endl;

}

