#pragma once
#ifndef SPEAKER_H
#define SPEAKER_H

#include "Person.h"

using namespace std;

class Speaker : public Person {
private:
    string report;      
    string annotation;  
public:
    // Конструкторы и деструктор
    Speaker();
    Speaker(const string& name, const string& organization, const string& report, const string& annotation);
    Speaker(const Speaker& other);
    ~Speaker();

    // Методы доступа
    string getReport() const;
    void setReport(const string& report);

    string getAnnotation() const;
    void setAnnotation(const string& annotation);

    // Переопределение виртуальной функции
    void displayInfo() const override;
};

#endif // SPEAKER_H
