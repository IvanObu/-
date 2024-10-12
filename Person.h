#ifndef PERSON_H
#define PERSON_H

#include <string>
using namespace std;

class Person {
protected:
    string name;
    string organization;

public:
    Person();
    Person(string name, string organization);
    virtual ~Person();
    
    // Getters и Setters
    string getName() const;
    void setName(const string& name);
    
    string getOrganization() const;
    void setOrganization(const string& organization);

    virtual void displayInfo() const = 0; // Чисто виртуальный метод
};

#endif
