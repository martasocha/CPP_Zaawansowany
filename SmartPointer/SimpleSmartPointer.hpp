#pragma once

template <typename T>
class SimpleSmartPointer
{
public:
	SimpleSmartPointer(T* data)
		: _data(data) //pozyskuje zasob w konstrukrorze
	{
	}
	~SimpleSmartPointer()
	{
		delete _data; //zwalnia zasob w konstruktorze
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
};

