// Zadanie3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <regex>

class User
{
public:
    User(std::string login, std::string password)
        : _login(login), _password(password)
    {
    }
    std::string getPassword()
    {
        return _password;
    }
    std::string getLogin()
    {
        return _login;
    }

private:
    std::string _login;
    std::string _password;
};

int main()
{
    std::ifstream file("secret_file.csv");

    if (!file.is_open())
    {
        std::cout << "Nie uda³o siê otworzyc pliku";
        return 0;
    }

    std::vector<User> users;



    std::string login;
    std::string password;
    std::string str;
    std::getline(file, str); //zjedzenie naglowka

    while (std::getline(file, login, ',')) //pilnuje zeby dojsc do konca strumienia i nie wczytac nic
    {
        std::getline(file, password);

        users.emplace_back(login, password);
    }
    file.close();

    std::vector<User> badPassword;

    auto checkPassword = [](User& user)
    {
        std::regex passwordRegex("^(?=.*[a-z])(?=.*[A-Z])(?=.*\d)[a-zA-Z\d]{8,}$");
        std::regex_match(user.getPassword(), passwordRegex);
        return user.getPassword().size() < 8;
    };

    std::copy_if(users.begin(), users.end(), std::back_inserter(badPassword), checkPassword);


    std::string fileName("wrongPassword.txt");
    std::ofstream fileToWrite(fileName, std::ios::out | std::ios::trunc);

    if (fileToWrite.is_open())
    {
        for (unsigned int i = 0; i < badPassword.size(); ++i)
        {
            if (fileToWrite.good())
            {
                fileToWrite << badPassword[i].getLogin() << "," << badPassword[i].getPassword() << "\n";
            }
        }
        fileToWrite.close();
    }
    else
    {
        std::cout << "Nie moge otworzyc pliku do zapisu";
        return -1;
    }

}