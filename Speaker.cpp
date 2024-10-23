#include "Speaker.h"

void Speaker::saveToFile(ofstream& file) {
    file << fullName << "\n";
    file << organization << "\n";
    file << topic << "\n";
    file << annotation << "\n";
}

void Speaker::loadFromFile(ifstream& file) {
    getline(file, fullName);
    getline(file, organization);
    getline(file, topic);
    getline(file, annotation);
}

void Speaker::menu() {
    int choice;
    do {
        cout << "Меню для Speaker:\n";
        cout << "1. Показать данные\n";
        cout << "2. Изменить имя\n";
        cout << "3. Изменить организацию\n";
        cout << "4. Изменить тему доклада\n";
        cout << "5. Изменить аннотацию\n";
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
            cout << "Введите новую организацию: ";
            cin.ignore();
            getline(cin, organization);
            break;
        }
        case 4: {
            cout << "Введите новую тему доклада: ";
            cin.ignore();
            getline(cin, topic);
            break;
        }
        case 5: {
            cout << "Введите новую аннотацию: ";
            cin.ignore();
            getline(cin, annotation);
            break;
        }
        }
    } while (choice != 0);
}

void Speaker::show() const {
    cout << "Спикер:\n";
    cout << "Имя: " << fullName << "\n";
    cout << "Организация: " << organization << "\n";
    cout << "Тема доклада: " << topic << "\n";
    cout << "Аннотация: " << annotation << "\n";
}
