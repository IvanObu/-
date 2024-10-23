#include "Program.h"

void Program::saveToFile(ofstream& file) {
    file << day << "\n";
    file << time << "\n";
    file << title << "\n";
}

void Program::loadFromFile(ifstream& file) {
    getline(file, day);
    getline(file, time);
    getline(file, title);
}

void Program::menu() {
    int choice;
    do {
        cout << "Меню для Program:\n";
        cout << "1. Показать данные\n";
        cout << "2. Изменить день\n";
        cout << "3. Изменить время\n";
        cout << "4. Изменить название программы\n";
        cout << "0. Выйти\n";
        cin >> choice;

        switch (choice) {
        case 1:
            show();
            break;
        case 2: {
            cout << "Введите новый день: ";
            cin.ignore();
            getline(cin, day);
            break;
        }
        case 3: {
            cout << "Введите новое время: ";
            cin.ignore();
            getline(cin, time);
            break;
        }
        case 4: {
            cout << "Введите новое название программы: ";
            cin.ignore();
            getline(cin, title);
            break;
        }
        }
    } while (choice != 0);
}

void Program::show() const {
    cout << "Программа:\n";
    cout << "День: " << day << "\n";
    cout << "Время: " << time << "\n";
    cout << "Название: " << title << "\n";
}
