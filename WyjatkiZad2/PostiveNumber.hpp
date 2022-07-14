#pragma once

class PositiveNumber
{
    double _value;

public:
    PositiveNumber();
    PositiveNumber(double value);
    PositiveNumber(float value);
    PositiveNumber(int value);
    virtual ~PositiveNumber() = default;
    PositiveNumber(const PositiveNumber&) = default; // CPP11 jawnie prosimy kompilator o wygenerowanie domyslego c-tora kopiujacego

    double getValue() const;
    void setValue(double value);
    void setValue(float value);
    void setValue(int value);

    void add(double value);
    void add(float value);
    void add(int value);
    void substract(double value);
    void substract(float value);
    void substract(int value);

    PositiveNumber& operator+ (const PositiveNumber& second);
    PositiveNumber& operator- (const PositiveNumber& second);
    PositiveNumber& operator+ (double number);
    PositiveNumber& operator- (double number);
    PositiveNumber& operator+ (float number);
    PositiveNumber& operator- (float number);
    PositiveNumber& operator+ (int number);
    PositiveNumber& operator- (int number);
    //oprtstor + - dla float i int
    //

};
