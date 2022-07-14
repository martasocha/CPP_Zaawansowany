#include "PostiveNumber.hpp"
#include <string>


PositiveNumber::PositiveNumber()
    : PositiveNumber(0.0)
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
        throw std::string("NIE MOZE BYC LICZBA UJEMNA");
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
        throw std::string("PROBUJESZ DODAC ZA DUZA LICZBE WYNIK BYLBY UJEMA");
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
        throw std::string("PROBUJESZ ODJAC ZA DUZA LICZBE WYNIK BYLBY LICZBA UJEMNA");
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



PositiveNumber& PositiveNumber::operator+(const PositiveNumber& second)
{
    //add(second.getValue());
    PositiveNumber result;
    result.add(second.getValue());
    return result;
}

PositiveNumber& PositiveNumber::operator-(const PositiveNumber& second)
{
    PositiveNumber result;
    result.substract(second.getValue());
    //this->substract(second.getValue());
    return result;
}

PositiveNumber& PositiveNumber::operator+(double number)
{
    PositiveNumber result;
    result.add(number);
    return result;
    //add(number);
}

PositiveNumber& PositiveNumber::operator-(double number)
{
    PositiveNumber result;
    result.substract(number);
    return result;
}

PositiveNumber& PositiveNumber::operator+(float number)
{
    PositiveNumber result;
    result.add(number);
    return result;
    //add(number);
}

PositiveNumber& PositiveNumber::operator-(float number)
{
    PositiveNumber result;
    result.substract(number);
    return result;
}

PositiveNumber& PositiveNumber::operator+(int number)
{
    PositiveNumber result;
    result.add(number);
    return result;
    //add(number);
}

PositiveNumber& PositiveNumber::operator-(int number)
{
    PositiveNumber result;
    result.substract(number);
    return result;
}
