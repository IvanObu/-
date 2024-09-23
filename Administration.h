#pragma once
#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Person.h"

using namespace std;

class Administration : public Person {
private:
    string position;  
    string responsibility;  
public:
    // Конструкторы и деструктор
    Administration();
    Administration(const string& name, const string& organization, const string& position, const string& responsibility);
    Administration(const Administration& other);
    ~Administration();

    // Методы доступа
    string getPosition() const;
    void setPosition(const string& position);

    string getResponsibility() const;
    void setResponsibility(const string& responsibility);

    // Переопределение виртуальной функции
    void displayInfo() const override;
};

#endif // ADMINISTRATION_H
