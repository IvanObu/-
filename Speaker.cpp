#include "Speaker.h"
#include <iostream>

using namespace std;

Speaker::Speaker() : Person(), report(""), annotation("") {
    cout << "Вызван конструктор Speaker по умолчанию." << endl;
}

Speaker::Speaker(string name, string organization, string report, string annotation)
    : Person(name, organization), report(report), annotation(annotation) {
    cout << "Вызван конструктор Speaker с параметрами." << endl;
}

Speaker::~Speaker() {
    cout << "Вызван деструктор Speaker." << endl;
}

string Speaker::getReport() const {
    return report;
}

void Speaker::setReport(const string& report) {
    this->report = report;
}

string Speaker::getAnnotation() const {
    return annotation;
}

void Speaker::setAnnotation(const string& annotation) {
    this->annotation = annotation;
}

void Speaker::displayInfo() const {
    cout << "ФИО: " << name << ", Организация: " << organization
         << ", Доклад: " << report << ", Аннотация: " << annotation << endl;
}

// Операции для работы с массивом выступающих
void Speaker::addSpeaker(Speaker*& speakers, int& count) {
    Speaker* newSpeakers = new Speaker[count + 1];
    for (int i = 0; i < count; ++i) {
        newSpeakers[i] = speakers[i];
    }

    string name, organization, report, annotation;
    cout << "Введите ФИО выступающего: ";
    cin.ignore();
    getline(cin, name);
    cout << "Введите организацию/ВУЗ: ";
    getline(cin, organization);
    cout << "Введите тему доклада: ";
    getline(cin, report);
    cout << "Введите аннотацию доклада: ";
    getline(cin, annotation);

    newSpeakers[count] = Speaker(name, organization, report, annotation);
    count++;

    delete[] speakers;
    speakers = newSpeakers;

    cout << "Выступающий добавлен!" << endl;
}

void Speaker::deleteSpeaker(Speaker*& speakers, int& count) {
    if (count == 0) {
        cout << "Список выступающих пуст!" << endl;
        return;
    }

    int index;
    cout << "Введите индекс выступающего для удаления (1 - " << count << "): ";
    cin >> index;

    if (index < 1 || index > count) {
        cout << "Неверный индекс!" << endl;
        return;
    }

    Speaker* newSpeakers = new Speaker[count - 1];
    for (int i = 0, j = 0; i < count; ++i) {
        if (i != index - 1) {
            newSpeakers[j++] = speakers[i];
        }
    }
    count--;

    delete[] speakers;
    speakers = newSpeakers;

    cout << "Выступающий удалён!" << endl;
}

void Speaker::listSpeakers(const Speaker* speakers, int count) {
    if (count == 0) {
        cout << "Список выступающих пуст!" << endl;
        return;
    }

    for (int i = 0; i < count; ++i) {
        cout << i + 1 << ". ";
        speakers[i].displayInfo();
    }
}
