#ifndef SPEAKER_H
#define SPEAKER_H

#include "Person.h"

class Speaker : public Person {
private:
    string report;
    string annotation;

public:
    Speaker();
    Speaker(string name, string organization, string report, string annotation);
    virtual ~Speaker();

    // Setters и Getters
    string getReport() const;
    void setReport(const string& report);

    string getAnnotation() const;
    void setAnnotation(const string& annotation);

    // Реализация чисто виртуального метода
    void displayInfo() const override;

    // Операции: добавление, удаление, отображение
    static void addSpeaker(Speaker*& speakers, int& count);
    static void deleteSpeaker(Speaker*& speakers, int& count);
    static void listSpeakers(const Speaker* speakers, int count);
};

#endif
