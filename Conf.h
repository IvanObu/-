#ifndef CONF_H
#define CONF_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Conf {
protected:
    string fullName;  // Для Speaker и Administration
public:
    Conf() : fullName("Unnamed") {}
    Conf(const string& name) : fullName(name) {}
    virtual ~Conf() {}

    // Виртуальные функции для наследников
    virtual void saveToFile(ofstream& file) = 0;
    virtual void loadFromFile(ifstream& file) = 0;
    virtual void menu() = 0;  // Меню, которое будет различным для каждого наследника

    virtual void show() const {
        cout << "Full Name: " << fullName << endl;
    }

    void setFullName(const string& name) {
        fullName = name;
    }

    string getFullName() const {
        return fullName;
    }
};

#endif // CONF_H
