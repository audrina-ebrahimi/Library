#ifndef PERSON_H
#define PERSON_H
#include <QtCore>

class Person
{
private:
    QString name;
    QString pass;
public:
    Person()
    {
        this->name = " ";
        this->pass = " ";
    }
    void set_name(QString name)
    {
        this->name = name;
    }
    QString get_name()
    {
        return this->name;
    }
    void set_pass(QString pass)
    {
        this->pass = pass;
    }
    QString get_pass()
    {
        return this->pass;
    }
};

#endif // PERSON_H
