#ifndef PROGRAM_H
#define PROGRAM_H

#include <string>
using namespace std;

class Program {
private:
    string day;
    string time;
    string title;

public:
    Program();
    Program(string day, string time, string title);
    ~Program();

    // Setters и Getters
    string getDay() const;
    void setDay(const string& day);

    string getTime() const;
    void setTime(const string& time);

    string getTitle() const;
    void setTitle(const string& title);

    // Вывод информации
    void displayInfo() const;

    // Операции: добавление, удаление, отображение
    static void addProgram(Program*& programs, int& count);
    static void deleteProgram(Program*& programs, int& count);
    static void listPrograms(const Program* programs, int count);
};

#endif
