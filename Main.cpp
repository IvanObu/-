#include <iostream>
#include "Speaker.h"
#include "Administration.h"
#include "Program.h"

using namespace std;

int main() {
    Speaker* speakers = nullptr;
    int speakerCount = 0;

    Administration* admins = nullptr;
    int adminCount = 0;

    Program* programs = nullptr;
    int programCount = 0;

    int choice;
    do {
        cout << "\nМеню конференции:" << endl;
        cout << "1. Добавить выступающего" << endl;
        cout << "2. Удалить выступающего" << endl;
        cout << "3. Показать всех выступающих" << endl;
        cout << "4. Добавить администратора" << endl;
        cout << "5. Удалить администратора" << endl;
        cout << "6. Показать всех администраторов" << endl;
        cout << "7. Добавить программу" << endl;
        cout << "8. Удалить программу" << endl;
        cout << "9. Показать все программы" << endl;
        cout << "0. Выход" << endl;
        cout << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
            case 1:
                Speaker::addSpeaker(speakers, speakerCount);
                break;
            case 2:
                Speaker::deleteSpeaker(speakers, speakerCount);
                break;
            case 3:
                Speaker::listSpeakers(speakers, speakerCount);
                break;
            case 4:
                Administration::addAdmin(admins, adminCount);
                break;
            case 5:
                Administration::deleteAdmin(admins, adminCount);
                break;
            case 6:
                Administration::listAdmins(admins, adminCount);
                break;
            case 7:
                Program::addProgram(programs, programCount);
                break;
            case 8:
                Program::deleteProgram(programs, programCount);
                break;
            case 9:
                Program::listPrograms(programs, programCount);
                break;
            case 0:
                cout << "Выход из программы." << endl;
                break;
            default:
                cout << "Неверный выбор!" << endl;
                break;
        }

    } while (choice != 0);

    // Освобождаем динамически выделенную память
    delete[] speakers;
    delete[] admins;
    delete[] programs;

    return 0;
}
