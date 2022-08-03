// Zadanie3.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>

class User
{
public:
    User(std::string login, std::string password)
        : _login(login), _password(password)
    {

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
    std::getline(file, str); //zjezenie naglowka

    while (std::getline(file, login, ',')) //pilnuje zeby dojsc do konca strumienia i nie wczytac nic
    {
        std::getline(file, password);

        users.emplace_back(login, password);
    }
    file.close();

    std::vector<Users> badPassword;
    auto checkPassword = [](const User& user)
    {
        std::regex_march
        return user.password.size() < 8;
    }
    std::copy_if(users.begin(), users.end(), std::back_inserter(badPassword), checkPassword);

    //while (file.good() && !file.eof())
    //{
    //    std::getline(file, login, ',');
    //    std::getline(file, password);

    //    users.emplace_back(login, password);
    //}

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
