#include <iostream>
#include <memory>
#include <vector>


/*
1.
Stw�rz klas� Chicken, kt�ra w konstruktorze i destruktorze wypisze
swoj� nazw�. Nast�pnie stw�rz funkcj� void fun(), kt�ra w �rodku utworzy dwa
wska�niki na dwa obiekty klasy Chicken (zwyk�y i uniqe_ptr). Zobacz jak
dzia�aj�, gdy wyjd� z zasi�gu.
*/

class Chicken
{
public:
	Chicken()
	{
		std::cout << "Chicken" << std::endl;
	}

	Chicken(const Chicken& second)
	{
		std::cout << "Chicken copy" << std::endl;
	}

	~Chicken()
	{
		std::cout << "~Chicken" << std::endl;
	}
};

void fun()
{
	Chicken* ptr  = new Chicken();
	std::unique_ptr<Chicken> smartPtr(new Chicken());

	delete ptr;
}

void funA(std::shared_ptr <Chicken> sharedPtr)
{

}

void copyChicken(int howMany, std::shared_ptr <Chicken> sharedPtr)
{
	std::vector<std::shared_ptr<Chicken>> chickens;
	for (unsigned int i = 0; i < howMany; ++i)
	{
		chickens.push_back(sharedPtr);
	}
}

int main()
{
	//fun();
	std::shared_ptr<Chicken> sharedPtr1(new Chicken());
	std::shared_ptr<Chicken> sharedPtr = std::make_shared<Chicken>(); // domyslna metoda, 1 blok pamieci(szybciej), zapewnia exception safety

	//funA(new Chicken());
	funA(std::make_shared<Chicken>()); // domyslnie make_shared

	copyChicken(10, sharedPtr);
	std::cout << "Chicken count" << sharedPtr.use_count();
	
	

}