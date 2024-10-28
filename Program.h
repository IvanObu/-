#ifndef PROGRAM_H
#define PROGRAM_H

#include "Conf.h"

class Program : public Conf {
private:
    string day;
    string time;
    string title;
public:
    Program() : day(""), time(""), title("") {}
    Program(const string& d, const string& t, const string& ttl)
        : Conf(""), day(d), time(t), title(ttl) {}
    Program(const Program& other)
        : Conf(other.fullName), day(other.day), time(other.time), title(other.title) {}
    ~Program() {}
    void saveToFile(ofstream& file) override;
    void loadFromFile(ifstream& file) override;
    void menu() override;
    void show() const override;
};

#endif // PROGRAM_H
