#include "Program.h"
#include <iostream>

Program::Program() : day(""), time(""), title("") {
    cout << "Вызван конструктор Program по умолчанию." << endl;
}

Program::Program(string day, string time, string title) : day(day), time(time), title(title) {
    cout << "Вызван конструктор Program с параметрами." << endl;
}

Program::~Program() {
    cout << "Вызван деструктор Program." << endl;
}

string Program::getDay() const {
    return day;
}

void Program::setDay(const string& day) {
    this->day = day;
}

string Program::getTime() const {
    return time;
}

void Program::setTime(const string& time) {
    this->time = time;
}

string Program::getTitle() const {
    return title;
}

void Program::setTitle(const string& title) {
    this->title = title;
}

void Program::displayInfo() const {
    cout << "День: " << day << ", Время: " << time << ", Название: " << title << endl;
}

// Операции для работы с программой
void Program::addProgram(Program*& programs, int& count) {
    Program* newPrograms = new Program[count + 1];
    for (int i = 0; i < count; ++i) {
        newPrograms[i] = programs[i];
    }

    string day, time, title;
    cout << "Введите день программы: ";
    cin.ignore();
    getline(cin, day);
    cout << "Введите время программы: ";
    getline(cin, time);
    cout << "Введите название программы: ";
    getline(cin, title);

    newPrograms[count] = Program(day, time, title);
    count++;

    delete[] programs;
    programs = newPrograms;

    cout << "Программа добавлена!" << endl;
}

void Program::deleteProgram(Program*& programs, int& count) {
    if (count == 0) {
        cout << "Список программ пуст!" << endl;
        return;
    }

    int index;
    cout << "Введите индекс программы для удаления (1 - " << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Неверный индекс!" << endl;
        return;
    }

    Program* newPrograms = new Program[count - 1];
    for (int i = 0, j = 0; i < count; ++i) {
        if (i != index - 1) {
            newPrograms[j++] = programs[i];
        }
    }
    count--;

    delete[] programs;
    programs = newPrograms;

    cout << "Программа удалена!" << endl;
}

void Program::listPrograms(const Program* programs, int count) {
    if (count == 0) {
        cout << "Список программ пуст!" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". ";
        programs[i].displayInfo();
    }
}
