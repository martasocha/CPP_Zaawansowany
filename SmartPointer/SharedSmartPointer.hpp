#pragma once
#include "RefCounter.hpp"

template<typename T>
class SharedSmartPointer
{
public:
	SharedSmartPointer()
		: _data(nullptr), reference(0)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(T* data)
		: _data(data)
	{
		reference = new RefCounter();

		reference->AddRef(); //zwiekszamy licznik o 1 bo juz istniejmy 
	}

	SharedSmartPointer(const SharedSmartPointer<T>& second)
		:_data(second._data), reference(second.reference) //kopiujemy reference, wiec wspoldzielimy wskaznik na licznik
	{
		reference->AddRef();
	}

	~SharedSmartPointer()
	{
		if (reference->Release() == 0) //jeœli wartosc licznika po release jest 0 - oznacza ze jestesmy ostatni i sprzatamy
		{
			delete _data;
			delete reference;
		}
	}

	SharedSmartPointer& operator = (const SharedSmartPointer<T>&another)
	{
		//Zabezpieczenie przed skopiowaniem samego siebie
		if (this != &another) //pobieramy adres z another, sprawdzamy czy jest ten sam
		{
			if (reference->Release() == 0)
			{
				//Zwolnienie starych danych
				delete _data;
				_data = nullptr;
				delete reference;
				reference == nullptr;
			}
			// mamy czysty this

			//Kopiuje dane z drugiego wskaźnika i zwiększam licznik
			this->_data = another._data;
			this->reference = another.reference;
			reference->AddRef();
			return *this; // zwracamy wyluskanie bo zwracamy referencję
		}
		else
		{
			return *this;
		}

	}

	T& operator*()
	{
		return *_data;
	}

	T* operator->()
	{
		return _data;
	}

private:
	T* _data;
	RefCounter* reference;
};