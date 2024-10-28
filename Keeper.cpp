#include "Keeper.h"
#include "Speaker.h"
#include "Administration.h"
#include "Program.h"

Keeper::Keeper() : conferences(nullptr), conferenceCount(0) {}

Keeper::~Keeper() {
    clear();
}

void Keeper::clear() {
    for (int i = 0; i < conferenceCount; ++i) {
        delete conferences[i];
    }
    delete[] conferences;
    conferenceCount = 0;
    conferences = nullptr;
}

void Keeper::addConference(Conf* conf) {
    Conf** temp = new Conf*[conferenceCount + 1];
    for (int i = 0; i < conferenceCount; ++i) {
        temp[i] = conferences[i];
    }
    temp[conferenceCount] = conf;
    delete[] conferences;
    conferences = temp;
    ++conferenceCount;
}

void Keeper::removeConference(int index) {
    if (index < 0 || index >= conferenceCount) {
        cerr << "Неверный индекс.\n";
        return;
    }
    delete conferences[index];
    for (int i = index; i < conferenceCount - 1; ++i) {
        conferences[i] = conferences[i + 1];
    }
    --conferenceCount;
}

void Keeper::showAllConferences() const {
    for (int i = 0; i < conferenceCount; ++i) {
        conferences[i]->show();
        cout << "-----------------------\n";
    }
}
ostream& operator<<(ostream& os, const Keeper& keeper) {
    for (int i = 0; i < keeper.conferenceCount; ++i) {
        keeper.conferences[i]->show();
        os << "-----------------------\n";
    }
    return os;
}

void Keeper::Ren(int index){
    if (index < 0 || index >= conferenceCount) {
        cerr << "Неверный индекс.\n";
        return;
    }
    conferences[index]->menu();
    conferences[index]->show();
    cout << "-----------------------\n";
}
void Keeper::saveToFile(const string& filename) {
    ofstream file(filename, ios::trunc);
    if (!file) {
        cerr << "Ошибка открытия файла для записи.\n";
        return;
    }

    for (int i = 0; i < conferenceCount; ++i) {
        if (dynamic_cast<Speaker*>(conferences[i])) {
            file << "[Speaker]\n";
        } else if (dynamic_cast<Administration*>(conferences[i])) {
            file << "[Administration]\n";
        } else if (dynamic_cast<Program*>(conferences[i])) {
            file << "[Program]\n";
        }
        conferences[i]->saveToFile(file);
    }

    file.close();
    cout << "Данные сохранены в файл.\n";
}

void Keeper::loadFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) {
        cerr << "Ошибка открытия файла для чтения.\n";
        return;
    }

    clear();
    string line;
    while (getline(file, line)) {
        Conf* conf = nullptr;
        if (line == "[Speaker]") {
            conf = new Speaker();
        } else if (line == "[Administration]") {
            conf = new Administration();
        } else if (line == "[Program]") {
            conf = new Program();
        }
        if (conf) {
            conf->loadFromFile(file);
            addConference(conf);
        }
    }
    file.close();
    cout << "Данные загружены из файла.\n";
}
