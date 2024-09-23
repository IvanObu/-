#pragma once
#ifndef PROGRAM_H
#define PROGRAM_H

#include <iostream>
#include <string>

using namespace std;

class Program {
private:
    string day;     
    string time;     
    string title;    
public:
    // Конструкторы и деструктор
    Program();
    Program(const string& day, const string& time, const string& title);
    Program(const Program& other);
    ~Program();

    // Методы доступа
    string getDay() const;
    void setDay(const string& day);

    string getTime() const;
    void setTime(const string& time);

    string getTitle() const;
    void setTitle(const string& title);

    // Вывод информации о программе
    void displayInfo() const;
};

#endif // PROGRAM_H
