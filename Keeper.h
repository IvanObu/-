#ifndef KEEPER_H
#define KEEPER_H

#include "Conf.h"
#include <fstream>

class Keeper {
private:
    Conf** conferences;
    int conferenceCount;

public:
    Keeper();
    ~Keeper();

    void addConference(Conf* conf);
    void removeConference(int index);
    void showAllConferences() const;

    void saveToFile(const string& filename);
    void loadFromFile(const string& filename);
    void Ren(int index);
    void clear();
};

#endif // KEEPER_H
