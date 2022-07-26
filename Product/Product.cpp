/*
2.
Zadanie: Stwórz klasê Product (float price, string name) oraz 2 konstruktory
(domyslny i z 2 parametrami). U¿ywaj¹c make_uniqe stwórz i przypisz do
uniqe_ptr:
Obiekt u¿ywaj¹c konstruktora domyœlnego
Obiekt u¿ywaj¹c konstruktora z 2 parametrami
///
Tablicê 4 Produktów

*/
#include <iostream>
#include<string>
#include<memory>

class Product
{
public:
    Product()
        : _price(0)
        , _name(" ")
    {
    }
    Product(float price, std::string name)
        : _price(price)
        , _name(name)
    {

    }
private:
    float _price;
    std::string _name;
};

int main()
{
   /* Product product1;
    std::unique_ptr<Product> ptr1 = std::make_unique<Product>(product1);*/

    std::unique_ptr<Product> ptr1 = std::make_unique<Product>();

    std::unique_ptr<Product> ptr2 = std::make_unique<Product>(100, "Chleb");

    std::unique_ptr<Product* []> ptr2 = std::make_unique<Product* []>();

   /* Product tab[4];
    tab[0] = Product (100, "Maka");
    tab[1] = Product(100, "Olej");
    tab[2] = Product(100, "Sok");
    tab[3] = Product(100, "Mleko");

    std::unique_ptr<Product> ptr3 = std::make_unique<Product>(tab[0]);*/

}

