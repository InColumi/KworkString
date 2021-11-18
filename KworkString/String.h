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
	String(size_t size); // �����������, ������� ������ ������ � �������� �������;
	String(const char* symbols);
	String(const String& s);
	String& operator=(const String& s);
	String(String&& s);
	String& operator=(String&& s);
	~String(); //  ����������;

	String concat(const String& s2); // -��������� ������ � ������;
	String operator+(const String& s); // ���������� ��������� + -������ ������ �oncat();
	int compare(const String& s); // -���������� ������ �� ������� � strcmp;
	char& operator[] (const size_t index);
	void reverse(); // -����������� ������;
	String operator*(size_t value);
	String& operator+=(const String& s);
	int find(char symbol); // -���������� ������ ��������� �������;
	int find(char symbol, size_t index); // -���������� ������ ������� ������� �� ��������� ���������;
	size_t size() const;
	String erase(size_t start, size_t end); // -������� ������� � ��������� ���������� � ��������� �������;
	void pop(); // -������� ��������� ������;
	void pop(size_t index); // -������� ������ �� �������;
};
#endif