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
    String(const String&); //копирующий конструктор;
    ~String(); //  Деструктор;
    
   String concat(const String& s2); // -соединяет строку с другой;
   void pop(); // -удаляет последний символ;
   void pop(size_t index); // -удаляет символ по индексу;
   size_t size() const; // -возвращает длину строки;
  
   
   bool compare(); // -сравнивает строки по аналогу с strcmp;
   void reverse(); // -реверсирует строку;
   size_t find(char symbol); // -возвращает индекс заданного символа;
   int find(char symbol, size_t index); // -возвращает индекс первого символа по заданному вхождению;
   String erase(size_t start, size_t end); // -удаляет символы с заданного начального и конечного индекса;
   String& operator+(const String& s); // Перегрузку оператора + -аналог метода сoncat();
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

    //конструктор без параметров
    MyString()
    {
        str = nullptr;
        length = 0;
    }

    //конструктор с параметрами, при создании объекта класса необходимо перелать строку которую он будет хранить
    MyString(char* str)
    {

        length = strlen(str);// функция strlen получает количество символов в строке которую мы передаём в объект

        // выделяем память для динамического массива где будет храниться наша строка
        // +1 символ так как нужно место в массиве под терминирующий 0
        this->str = new char[length + 1];

        // копируем символы строки в массив нашего класса
        for(int i = 0; i < length; i++)
        {
            this->str[i] = str[i];
        }

        //закрываем строку терминирующим нулём
        this->str[length] = '\0';

    }
    // деструктор, отвечает за освобождение ресурвов занятых объектом, вызывается при уничтожении объекта класса
    ~MyString()
    {
        delete[] this->str;
    }

    // конструктор копировании, необходим для создании точной копи объекта класса но в другой области памяти
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

    // перегруженый оператор присваивания, вызывается когда необходимо присвоить значение одного объекта другому
    MyString& operator =(const MyString& other)
    {
        // здесь логика похожа на ту которая реализована в конструкторе, за исключением того, что нам нужно позаботиться
        // об освобождении ресурсов объекта если до копирования в него новой строки он уже содержал код
        //+ страндартный синтаксис перегрузки оператора =
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

    //перегруженный оператор сложения, в текущей реализации класса String необходим для конкатенации строк
    MyString operator+(const MyString& other)
    {
        //создаём новый пустой объект где будим хранить результат конкатенации строк и который будет результатом работы
        // перегруженного оператора +
        MyString newStr;
        // получаем количество символов в обеих строках для конкатенации

        int thisLength = strlen(this->str);
        int otherLength = strlen(other.str);

        newStr.length = thisLength + otherLength;

        // выделяем место в динамической памяти под новую строку
        newStr.str = new char[thisLength + otherLength + 1];

        //копируем данные из 2х конкатенируемых строк в новую строку
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

        // возвращаем результат конкатенации
        return newStr;
    }

   
private:
    // Указатель на массив char, хранит символы, которые мы передали в наш объект.
    char* str;
    int length;
};

#endif