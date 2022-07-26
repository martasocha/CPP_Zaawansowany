#include <iostream>
#include <memory>
#include <vector>


/*
1.
Stwórz klasê Chicken, która w konstruktorze i destruktorze wypisze
swoj¹ nazwê. Nastêpnie stwórz funkcjê void fun(), która w œrodku utworzy dwa
wskaŸniki na dwa obiekty klasy Chicken (zwyk³y i uniqe_ptr). Zobacz jak
dzia³aj¹, gdy wyjd¹ z zasiêgu.
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