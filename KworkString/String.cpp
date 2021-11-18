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

String::String(const String& s)
{
	_size = strlen(s._symbols);
	_symbols = new char[_size + 1];
	for(size_t i = 0; i < _size; i++)
	{
		_symbols[i] = s._symbols[i];
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

	char* newSymbols = new char[_size - 1];
	for(size_t i = 0; i < _size - 1; i++)
	{
		newSymbols[i] = _symbols[i];
	}
	newSymbols[_size - 1] = '\0';
	delete[] _symbols;
	_symbols = newSymbols;
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

	char* newSymbols = new char[_size - 1];
	for(size_t i = 0; i < index; i++)
	{
		newSymbols[i] = _symbols[i];
	}

	for(size_t i = index + 1; i < _size; i++)
	{
		newSymbols[i] = _symbols[i];
	}

	delete[] _symbols;
	_symbols = newSymbols;
	--_size;
}

String String::operator+(const String& s)
{
	return this->concat(s);
}

int String::compare(const String& s)
{
	int result;
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

size_t String::size() const
{
	return _size;
}