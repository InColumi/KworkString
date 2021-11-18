#include "String.h"
#include <stdexcept>

String::String()
{
	_size = 0;
	_symbols = nullptr;
}

String::String(size_t size)
{
	_size = size;
	_symbols = new char[_size + 1];
	_symbols[_size] = '\0';
}

String::String(const char* symbols)
{
	_size = strlen(symbols);
	_symbols = new char[_size + 1];
	for(size_t i = 0; i < _size; i++)
	{
		_symbols[i] = symbols[i];
	}
	_symbols[_size] = '\0';
}

String::~String()
{
	delete[] _symbols;
}

String String::concat(const String& s)
{
	String newString(_size + s._size + 1);
	for(size_t i = 0; i < _size; i++)
	{
		newString._symbols[i] = _symbols[i];
	}

	size_t k = _size;
	for(size_t i = 0; i < newString._size; i++, k++)
	{
		newString._symbols[k] = s._symbols[i];
	}
	newString._symbols[_size + s._size] = '\0';
	return newString;
}

void String::pop()
{
	if(_size == 0)
	{
		return;
	}
	size_t newSize = _size - 1;
	char* newSymbols = new char[newSize + 1];
	for(size_t i = 0; i < newSize; i++)
	{
		newSymbols[i] = _symbols[i];
	}
	newSymbols[newSize] = '\0';
	delete[] _symbols;
	_symbols = newSymbols;
	_size = newSize;
}

void String::pop(size_t index)
{
	if(_size == 0)
	{
		return;
	}

	if(index >= _size)
	{
		throw std::invalid_argument("Index must be in interval [0, size)!");
	}
	size_t newSize = _size - 1;
	char* newSymbols = new char[newSize + 1];
	for(size_t i = 0; i < index; i++)
	{
		newSymbols[i] = _symbols[i];
	}

	for(size_t i = index + 1; i < _size; i++)
	{
		newSymbols[i - 1] = _symbols[i];
	}

	newSymbols[newSize] = '\0';
	delete[] _symbols;
	_symbols = newSymbols;
	_size = newSize;
}

String String::operator+(const String& s)
{
	return this->concat(s);
}

size_t String::size() const
{
	return _size;
}

int String::compare(const String& s)
{
	if(s._size == _size)
	{
		size_t index = 0;
		while(index != _size)
		{
			if(s._symbols[index] != _symbols[index])
			{
				return -1;
				break;
			}
			++index;
		}
		return 0;
	}
	else
	{
		return _size < s._size ? -1 : 1;
	}
}

char& String::operator[] (const size_t index)
{
	if(index >= _size)
	{
		throw std::invalid_argument("Index must be in interval [0, size)!");
	}
	return _symbols[index];
}

void String::reverse()
{
	if(_size == 0)
	{
		return;
	}

	char symbol;
	size_t size2 = _size / 2;
	for(size_t i = 0; i < size2; i++)
	{
		symbol = _symbols[i];
		_symbols[i] = _symbols[_size - 1 - i];
		_symbols[_size - 1 - i] = symbol;
	}
}

String String::operator*(size_t size)
{
	if(size == 0 || size == 1)
	{
		return *this;
	}

	size_t newSize = _size * size;
	char* newSymbols = new char[newSize + 1];

	for(size_t i = 0; i < size; i++)
	{
		for(size_t j = 0; j < _size; j++)
		{
			newSymbols[j + i * _size] = _symbols[j];
		}
	}

	newSymbols[newSize] = '\0';

	return String(newSymbols);
}

String& String::operator+=(const String& s)
{
	size_t newSize = _size + s._size;
	char* newSymbols = new char[newSize + 1];

	for(size_t i = 0; i < _size; i++)
	{
		newSymbols[i] = _symbols[i];
	}

	for(size_t i = 0; i < s._size; i++)
	{
		newSymbols[i + _size] = s._symbols[i];
	}
	newSymbols[newSize] = '\0';

	delete[] _symbols;
	_symbols = newSymbols;
	_size = newSize;

	return *this;
}

int String::find(char symbol)
{
	for(size_t i = 0; i < _size; i++)
	{
		if(_symbols[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

int String::find(char symbol, size_t index)
{
	if(index >= _size)
	{
		throw std::invalid_argument("Index must be in interval [0, size)!");
	}

	for(size_t i = index; i < _size; i++)
	{
		if(_symbols[i] == symbol)
		{
			return i;
		}
	}
	return -1;
}

String String::erase(size_t start, size_t end)
{
	if(end >= _size || start >= end)
	{
		throw std::invalid_argument("Index must be in interval [0, size)!");
	}

	size_t differents = end - start;
	size_t newSize = _size - differents;
	char* newSymbols = new char[newSize + 1];

	for(size_t i = 0; i < start; i++)
	{
		newSymbols[i] = _symbols[i];
	}

	for(size_t i = end; i < _size; i++)
	{
		newSymbols[i - end] = _symbols[i];
	}
	newSymbols[newSize] = '\0';

	delete[] _symbols;
	_symbols = newSymbols;
	_size = newSize;

	return *this;
}

String::String(const String& s): _symbols(nullptr), _size(s._size)
{
	_symbols = new char[_size];
	for(size_t i = 0; i < _size; i++)
	{
		_symbols[i] = s._symbols[i];
	}
}

String& String::operator=(const String& s)
{
	if(_symbols)
		delete[] _symbols;

	_size = s._size;
	_symbols = new char[_size];
	memcpy(_symbols, s._symbols, _size);
	return *this;
}

String::String(String&& s): _symbols(s._symbols), _size(s._size)
{
	s._symbols = nullptr;
}

String& String::operator=(String&& s)
{
	if(_symbols)
		delete[] _symbols;

	_size = s._size;
	_symbols = s._symbols;
	s._symbols = nullptr;
	return *this;
}