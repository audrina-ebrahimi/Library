#ifndef BOOK_H
#define BOOK_H

#include <QString>

class book
{
public:
    book(QString name , QString author , QString subject , QString publisher , QString ISBN , QString language , int pageNum , int available);
    QString get_name();
    QString get_author();
    QString get_subject();
    QString get_publisher();
    QString get_ISBN();
    QString get_language();
    int get_pageNum();
    int get_availNum();
private:
    QString name;
    QString author;
    QString subject;
    QString publisher;
    QString ISBN;
    QString language;
    int pageNum;
    int available;
};

#endif // BOOK_H
