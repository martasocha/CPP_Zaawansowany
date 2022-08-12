#pragma once
#include <vector>
#include <fstream>


class File
{
public:
	enum class OpenMode {
		WRITE, //out | app
		READ //in
	};

	File(const std::string& filePath, OpenMode openMode); //w c-torze otwieramy plik (in, out | app)
	~File(); //w d-torze zamykamy plik

	template<typename T>
	friend const File& operator<<(const File& file, T data);

	template<typename T>
	friend const File& operator>>(const File& file, T data);

	template<typename T>
	T readValue();

	template<typename T>
	void writeValue(T value);

private:
	std::fstream _filestream;
};


template<typename T>
inline void File::writeValue(T value)
{
	if (_filestream.is_open())
	{
		std::cout << "Plik zosta³ wczytany " << std::endl << std::endl;
	}
	else
	{
		std::cout << "Nie mogê otworzyæ pliku";
	}

	if (_filestream.good())
	{
		_filestream << value;
	}
}


template<typename T>
inline T File::readValue()
{
	if (_filestream.is_open())
	{
		std::cout << "Plik zostal otwarty: " << std::endl << std::endl;
	}
	else
	{
		std::cout << "Nie mogê otworzyæ pliku";
		return -1;
	}
	
	if (_filestream.good() && !_filestream.eof())
	{
		T temp;
		_filestream >> temp;
		return temp;
	}
}

//template<typename T>
//const File& operator<<(const File& file, T data)
//{
//	if (File::OpenMode::READ)
//	{
//		file >> data;
//		return data;
//	}
//		throw std::invalid_argument;
//}
//
//template<typename T>
//const File& operator>>(const File& file, T data)
//{
//	if (File::OpenMode::WRITE)
//		throw std::invalid_argument;
//}