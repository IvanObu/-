#ifndef ADMINISTRATION_H
#define ADMINISTRATION_H

#include "Conf.h"

class Administration : public Conf {
private:
    string position;
    string responsibility;
public:
    Administration() : position(""), responsibility("") {}
    Administration(const string& name, const string& pos, const string& resp)
        : Conf(name), position(pos), responsibility(resp) {}
    Administration(const Administration& other)
        : Conf(other.fullName), position(other.position), responsibility(other.responsibility) {}
    ~Administration() {}
    void saveToFile(ofstream& file) override;
    void loadFromFile(ifstream& file) override;
    void menu() override;
    void show() const override;
};

#endif // ADMINISTRATION_H
