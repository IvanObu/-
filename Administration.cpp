#include "Administration.h"

void Administration::saveToFile(ofstream& file) {
    file << fullName << "\n";
    file << position << "\n";
    file << responsibility << "\n";
}

void Administration::loadFromFile(ifstream& file) {
    getline(file, fullName);
    getline(file, position);
    getline(file, responsibility);
}

void Administration::menu() {
    int choice;
    do {
        cout << "Меню для Administration:\n";
        cout << "1. Показать данные\n";
        cout << "2. Изменить имя\n";
        cout << "3. Изменить должность\n";
        cout << "4. Изменить ответственность\n";
        cout << "0. Выйти\n";
        cin >> choice;

        switch (choice) {
        case 1:
            show();
            break;
        case 2: {
            string newName;
            cout << "Введите новое имя: ";
            cin.ignore();
            getline(cin, newName);
            setFullName(newName);
            break;
        }
        case 3: {
            cout << "Введите новую должность: ";
            cin.ignore();
            getline(cin, position);
            break;
        }
        case 4: {
            cout << "Введите новую область ответственности: ";
            cin.ignore();
            getline(cin, responsibility);
            break;
        }
        }
    } while (choice != 0);
}

void Administration::show() const {
    cout << "Администрация:\n";
    cout << "Имя: " << fullName << "\n";
    cout << "Должность: " << position << "\n";
    cout << "Область ответственности: " << responsibility << "\n";
}
