#include <iostream>
#include "Keeper.h"
#include "Speaker.h"
#include "Administration.h"
#include "Program.h"
using namespace std;
int main() {
    Keeper keeper;
    int choice;

    do {
        cout << "Меню:\n";
        cout << "1. Добавить спикера\n";
        cout << "2. Добавить администратора\n";
        cout << "3. Добавить программу\n";
        cout << "4. Показать все конференции\n";
        cout << "5. Удалить конференцию\n";
        cout << "6. Сохранить в файл\n";
        cout << "7. Загрузить из файла\n";
        cout << "8. Редактировать запись\n";
        cout << "0. Выход\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            string name, org, top, ann;
            cout << "Введите ФИО спикера: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите организацию: ";
            getline(cin, org);
            cout << "Введите тему доклада: ";
            getline(cin, top);
            cout << "Введите аннотацию: ";
            getline(cin, ann);
            keeper.addConference(new Speaker(name, org, top, ann));
            break;
        }
        case 2: {
            string name, pos, resp;
            cout << "Введите ФИО администратора: ";
            cin.ignore();
            getline(cin, name);
            cout << "Введите должность: ";
            getline(cin, pos);
            cout << "Введите область ответственности: ";
            getline(cin, resp);
            keeper.addConference(new Administration(name, pos, resp));
            break;
        }
        case 3: {
            string day, time, title;
            cout << "Введите день проведения: ";
            cin.ignore();
            getline(cin, day);
            cout << "Введите время проведения: ";
            getline(cin, time);
            cout << "Введите название программы: ";
            getline(cin, title);
            keeper.addConference(new Program(day, time, title));
            break;
        }
        case 4:
            keeper.showAllConferences();
            break;
        case 5: {
            int index;
            cout << "Введите индекс конференции для удаления: ";
            cin >> index;
            keeper.removeConference(index - 1);
            break;
        }
        case 6: {
            string filename;
            cout << "Введите имя файла для сохранения: ";
            cin >> filename;
            keeper.saveToFile(filename);
            break;
        }
        case 7: {
            string filename;
            cout << "Введите имя файла для загрузки: ";
            cin >> filename;
            keeper.loadFromFile(filename);
            break;
        }
        case 8: {
            int index;
            cout << "Введите индекс конференции для редактирования: ";
            cin >> index;
            keeper.Ren(index - 1);
            break;
        }
        }
    } while (choice != 0);

    return 0;
}
