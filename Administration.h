#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Person.h"

class Administration : public Person {
private:
    string position;
    string responsibility;

public:
    Administration();
    Administration(string name, string organization, string position, string responsibility);
    virtual ~Administration();

    // Setters и Getters
    string getPosition() const;
    void setPosition(const string& position);

    string getResponsibility() const;
    void setResponsibility(const string& responsibility);

    // Реализация чисто виртуального метода
    void displayInfo() const override;

    // Операции: добавление, удаление, отображение
    static void addAdmin(Administration*& admins, int& count);
    static void deleteAdmin(Administration*& admins, int& count);
    static void listAdmins(const Administration* admins, int count);
};

#endif
