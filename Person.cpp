#include "Person.h"
#include <iostream>

Person::Person() : name(""), organization("") {
    cout << "Вызван конструктор Person по умолчанию." << endl;
}

Person::Person(string name, string organization) : name(name), organization(organization) {
    cout << "Вызван конструктор Person с параметрами." << endl;
}

Person::~Person() {
    cout << "Вызван деструктор Person." << endl;
}

string Person::getName() const {
    return name;
}

void Person::setName(const string& name) {
    this->name = name;
}

string Person::getOrganization() const {
    return organization;
}

void Person::setOrganization(const string& organization) {
    this->organization = organization;
}
