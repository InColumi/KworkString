#pragma once
#ifndef STRING_H
#define STRING_H
#include <iostream>

class String
{
private:
	char* _symbols;
	size_t _size;
public:

	String();
	String(size_t size); // Конструктор, который создаёт строку с заданным объемом;
	String(const char* symbols);
	String(const String& s);
	String& operator=(const String& s);
	String(String&& s);
	String& operator=(String&& s);
	~String(); //  Деструктор;

	String concat(const String& s2); // -соединяет строку с другой;
	String operator+(const String& s); // Перегрузку оператора + -аналог метода сoncat();
	int compare(const String& s); // -сравнивает строки по аналогу с strcmp;
	char& operator[] (const size_t index);
	void reverse(); // -реверсирует строку;
	String operator*(size_t value);
	String& operator+=(const String& s);
	int find(char symbol); // -возвращает индекс заданного символа;
	int find(char symbol, size_t index); // -возвращает индекс первого символа по заданному вхождению;
	size_t size() const;
	String erase(size_t start, size_t end); // -удаляет символы с заданного начального и конечного индекса;
	void pop(); // -удаляет последний символ;
	void pop(size_t index); // -удаляет символ по индексу;
};
#endif