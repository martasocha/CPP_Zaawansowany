#include "PostiveNumber.hpp"
#include <stdexcept>


PositiveNumber::PositiveNumber() // noexcept ta funkcja nie rzuca wyjatkow
    : _value(0.0)
{
}

PositiveNumber::PositiveNumber(double value)
{
    setValue(value);
}

PositiveNumber::PositiveNumber(float value) 
    : PositiveNumber(static_cast<double>(value))
{
}

PositiveNumber::PositiveNumber(int value)
    : PositiveNumber(static_cast<double>(value))
{
}

double PositiveNumber::getValue() const
{
    return _value;
}

void PositiveNumber::setValue(double value)
{
    if (value < 0)
    {
        throw std::out_of_range("NIE MOZE BYC LICZBA UJEMNA");
    }
    else
    {
        _value = value;
    }
}

void PositiveNumber::setValue(float value)
{
    setValue(static_cast<double>(value));
}

void PositiveNumber::setValue(int value)
{
    setValue(static_cast<double>(value));
}

void PositiveNumber::add(double value)
{
    if (value <0 && abs(value) > this->getValue())
    {
        throw std::out_of_range("PROBUJESZ DODAC ZA DUZA LICZBE WYNIK BYLBY UJEMA");
    }
    else
    {
        this->setValue(this->getValue() + value);
    }
}

void PositiveNumber::add(float value)
{
    add(static_cast<double>(value));
}

void PositiveNumber::add(int value)
{
    add(static_cast<double>(value));
}

void PositiveNumber::substract(double value)
{
    if (this->getValue() < value)
    {
        throw std::out_of_range("PROBUJESZ ODJAC ZA DUZA LICZBE WYNIK BYLBY LICZBA UJEMNA"); // tutaj wywolany jest konstruktor, rzucany jest obiekt tymczasowy (nie ma nazwy), zamiast
        // std:: out_of_range exception ("Bla bla");
        // throw exception; // wrzucamy obiekt lokalny
    }
    else
    {
        this->setValue(this->getValue() - value);
    }
}

void PositiveNumber::substract(float value)
{
    substract(static_cast<double>(value));
}

void PositiveNumber::substract(int value)
{
    substract(static_cast<double>(value));
}



//PositiveNumber& PositiveNumber::operator+(const PositiveNumber& second)
//{
//    //add(second.getValue());
//    add(second.getValue());
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator-(const PositiveNumber& second)
//{
//    //PositiveNumber result;
//    //result.substract(second.getValue());
//    this->substract(second.getValue());
//    return *this;
//}

PositiveNumber& PositiveNumber::operator=(const PositiveNumber& second)
{
    this->setValue(second.getValue());
    return *this;
}

//PositiveNumber& PositiveNumber::operator+(double number)
//{
//    add(number);
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator-(double number)
//{
//    substract(number);
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator+(float number)
//{
//    add(number);
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator-(float number)
//{
//    substract(number);
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator+(int number)
//{
//    add(number);
//    return *this;
//}
//
//PositiveNumber& PositiveNumber::operator-(int number)
//{
//    substract(number);
//    return *this;
//}

#include "PostiveNumber.hpp"

PositiveNumber operator+(double first, const PositiveNumber& second)
{
    PositiveNumber tmp;
    tmp.setValue(first + second.getValue());
    return tmp;
}

PositiveNumber operator-(double first, const PositiveNumber& second)
{
    PositiveNumber tmp;
    tmp.setValue(second.getValue() + first);
    return tmp;
}

PositiveNumber& operator+(const PositiveNumber& first, double second)
{
    PositiveNumber tmp(first);
    tmp.setValue(first.getValue() + second);
    return tmp;
}

PositiveNumber& operator-(const PositiveNumber& first, double second)
{
    PositiveNumber tmp;
    tmp.setValue(first.getValue() - second);
    return tmp;
}

PositiveNumber& operator+(const PositiveNumber& first, const PositiveNumber& second)
{
    PositiveNumber tmp(first);
    tmp.add(second.getValue());
    return tmp;
}

PositiveNumber& operator-(const PositiveNumber& first, const PositiveNumber& second)
{
    PositiveNumber tmp(first);
    tmp.substract(second.getValue());
    return tmp;
}
