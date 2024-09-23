#pragma once
#ifndef PERSON_H
#define PERSON_H

#include <iostream>
#include <string>

using namespace std;

class Person {
protected:
    string name;
    string organization;  
public:
    // Конструкторы и деструктор
    Person();
    Person(const string& name, const string& organization);
    Person(const Person& other);
    virtual ~Person();

    // Методы доступа
    string getName() const;
    void setName(const string& name);

    string getOrganization() const;
    void setOrganization(const string& organization);

    // Виртуальная функция вывода информации
    virtual void displayInfo() const = 0;
};

#endif // PERSON_H
