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
    String(const String&); //���������� �����������;
    ~String(); //  ����������;
    
   String concat(const String& s2); // -��������� ������ � ������;
   void pop(); // -������� ��������� ������;
   void pop(size_t index); // -������� ������ �� �������;
   size_t size() const; // -���������� ����� ������;
  
   
   bool compare(); // -���������� ������ �� ������� � strcmp;
   void reverse(); // -����������� ������;
   size_t find(char symbol); // -���������� ������ ��������� �������;
   int find(char symbol, size_t index); // -���������� ������ ������� ������� �� ��������� ���������;
   String erase(size_t start, size_t end); // -������� ������� � ��������� ���������� � ��������� �������;
   String& operator+(const String& s); // ���������� ��������� + -������ ������ �oncat();
   String& operator+=(const String& s); 
   String& operator*(size_t value);
   int operator[] (const size_t index)
   {
       return _symbols[index];
   }

   friend std::ostream& operator<< (std::ostream& out, const String& s)
   {
       for(size_t i = 0; i < s._size; i++)
       {
           out << s._symbols[i];
       }
       return out;
   }
};

class MyString
{
public:

    //����������� ��� ����������
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //����������� � �����������, ��� �������� ������� ������ ���������� �������� ������ ������� �� ����� �������
    MyString(char* str)
    {

        length = strlen(str);// ������� strlen �������� ���������� �������� � ������ ������� �� ������� � ������

        // �������� ������ ��� ������������� ������� ��� ����� ��������� ���� ������
        // +1 ������ ��� ��� ����� ����� � ������� ��� ������������� 0
        this->str = new char[length + 1];

        // �������� ������� ������ � ������ ������ ������
        for(int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        //��������� ������ ������������� ����
        this->str[length] = '\0';

    }
    // ����������, �������� �� ������������ �������� ������� ��������, ���������� ��� ����������� ������� ������
    ~MyString()
    {
        delete[] this->str;
    }

    // ����������� �����������, ��������� ��� �������� ������ ���� ������� ������ �� � ������ ������� ������
    MyString(const MyString& other)
    {
        length = strlen(other.str);
        this->str = new char[length + 1];

        for(int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';
    }

    // ������������ �������� ������������, ���������� ����� ���������� ��������� �������� ������ ������� �������
    MyString& operator =(const MyString& other)
    {
        // ����� ������ ������ �� �� ������� ����������� � ������������, �� ����������� ����, ��� ��� ����� ������������
        // �� ������������ �������� ������� ���� �� ����������� � ���� ����� ������ �� ��� �������� ���
        //+ ������������ ��������� ���������� ��������� =
        if(this->str != nullptr)
        {
            delete[] str;
        }

        length = strlen(other.str);
        this->str = new char[length + 1];

        for(int i = 0; i < length; i++)
        {
            this->str[i] = other.str[i];
        }

        this->str[length] = '\0';

        return *this;

    }

    //������������� �������� ��������, � ������� ���������� ������ String ��������� ��� ������������ �����
    MyString operator+(const MyString& other)
    {
        //������ ����� ������ ������ ��� ����� ������� ��������� ������������ ����� � ������� ����� ����������� ������
        // �������������� ��������� +
        MyString newStr;
        // �������� ���������� �������� � ����� ������� ��� ������������

        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);

        newStr.length = thisLength + otherLength;

        // �������� ����� � ������������ ������ ��� ����� ������
        newStr.str = new char[thisLength + otherLength + 1];

        //�������� ������ �� 2� ��������������� ����� � ����� ������
        int i = 0;
        for(; i < thisLength; i++)
        {
            newStr.str[i] = this->str[i];
        }

        for(int j = 0; j < otherLength; j++, i++)
        {
            newStr.str[i] = other.str[j];
        }

        newStr.str[thisLength + otherLength] = '\0';

        // ���������� ��������� ������������
        return newStr;
    }

   
private:
    // ��������� �� ������ char, ������ �������, ������� �� �������� � ��� ������.
    char* str;
    int length;
};

#endif