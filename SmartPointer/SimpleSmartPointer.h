#pragma once

template <typename T>
class SimpleSmartPointer
{
public:
	SimpleSmartPointer(T* data)
		: _data(data)
	{
	}
	~SimpleSmartPointer()
	{
		delete _data;
	}
	T operator*()
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

