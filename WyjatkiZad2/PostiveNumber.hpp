#pragma once //tylko raz ten plik bedzie zaczytamy, cokolwiek tutaj jest napisane powinno byc zadeklarowane tylko raz

class PositiveNumber
{
    double _value;

public:
    PositiveNumber();
    PositiveNumber(double value);
    PositiveNumber(float value);
    PositiveNumber(int value);
    virtual ~PositiveNumber() = default; // generowanie domysle destruktora, nie mamy nic do niszczenia, destruktor wirtualny na wypadek dziedziczenia, standard CPP11
    PositiveNumber(const PositiveNumber&) = default; // CPP11 jawnie prosimy kompilator o wygenerowanie domyslego c-tora kopiujacego

    double getValue() const; //const nie zmienia sie dla naszej klasy
    void setValue(double value);
    void setValue(float value);
    void setValue(int value);

    void add(double value);
    void add(float value);
    void add(int value);

    void substract(double value);
    void substract(float value);
    void substract(int value);

    //PositiveNumber& operator+ (const PositiveNumber& second);
    //PositiveNumber& operator- (const PositiveNumber& second);

    //PositiveNumber& operator+ (double number);
    //PositiveNumber& operator- (double number);

    //oprtstor + - dla float i int
    //
    PositiveNumber& operator=(const PositiveNumber& second);

};

PositiveNumber operator+ (double first, const PositiveNumber& second);
PositiveNumber operator- (double first, const PositiveNumber& second);
PositiveNumber& operator+ (const PositiveNumber& first, double second);
PositiveNumber& operator- (const PositiveNumber& first, double second);
PositiveNumber& operator+ (const PositiveNumber& first, const PositiveNumber& second);
PositiveNumber& operator- (const PositiveNumber& first, const PositiveNumber& second);

//nie moze wywolywac obiektow klasy i zwraca nowy obiekt