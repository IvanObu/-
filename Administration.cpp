#include "Administration.h"
#include <iostream>

Administration::Administration() : Person(), position(""), responsibility("") {
    cout << "Вызван конструктор Administration по умолчанию." << endl;
}

Administration::Administration(string name, string organization, string position, string responsibility)
    : Person(name, organization), position(position), responsibility(responsibility) {
    cout << "Вызван конструктор Administration с параметрами." << endl;
}

Administration::~Administration() {
    cout << "Вызван деструктор Administration." << endl;
}

string Administration::getPosition() const {
    return position;
}

void Administration::setPosition(const string& position) {
    this->position = position;
}

string Administration::getResponsibility() const {
    return responsibility;
}

void Administration::setResponsibility(const string& responsibility) {
    this->responsibility = responsibility;
}

void Administration::displayInfo() const {
    cout << "ФИО: " << name << ", Организация: " << organization
         << ", Должность: " << position << ", Ответственность: " << responsibility << endl;
}

// Операции для работы с администраторами
void Administration::addAdmin(Administration*& admins, int& count) {
    Administration* newAdmins = new Administration[count + 1];
    for (int i = 0; i < count; ++i) {
        newAdmins[i] = admins[i];
    }

    string name, organization, position, responsibility;
    cout << "Введите ФИО администратора: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите организацию: ";
    getline(cin, organization);
    cout << "Введите должность: ";
    getline(cin, position);
    cout << "Введите область ответственности: ";
    getline(cin, responsibility);

    newAdmins[count] = Administration(name, organization, position, responsibility);
    count++;

    delete[] admins;
    admins = newAdmins;

    cout << "Администратор добавлен!" << endl;
}

void Administration::deleteAdmin(Administration*& admins, int& count) {
    if (count == 0) {
        cout << "Список администраторов пуст!" << endl;
        return;
    }

    int index;
    cout << "Введите индекс администратора для удаления (1 - " << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Неверный индекс!" << endl;
        return;
    }

    Administration* newAdmins = new Administration[count - 1];
    for (int i = 0, j = 0; i < count; ++i) {
        if (i != index - 1) {
            newAdmins[j++] = admins[i];
        }
    }
    count--;

    delete[] admins;
    admins = newAdmins;

    cout << "Администратор удалён!" << endl;
}

void Administration::listAdmins(const Administration* admins, int count) {
    if (count == 0) {
        cout << "Список администраторов пуст!" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". ";
        admins[i].displayInfo();
    }
}
