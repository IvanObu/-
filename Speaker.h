#ifndef SPEAKER_H
#define SPEAKER_H

#include "Conf.h"

class Speaker : public Conf {
private:
    string organization;
    string topic;
    string annotation;
public:
    Speaker() : organization(""), topic(""), annotation("") {}
    Speaker(const string& name, const string& org, const string& top, const string& ann)
        : Conf(name), organization(org), topic(top), annotation(ann) {}
    Speaker(const Speaker& other)
    : Conf(other.fullName), organization(other.organization), topic(other.topic), annotation(other.annotation) {}
    ~Speaker() {}
    void saveToFile(ofstream& file) override;
    void loadFromFile(ifstream& file) override;
    void menu() override;
    void show() const override;
};

#endif // SPEAKER_H
