#include "book.h"

book::book(QString name , QString author , QString subject , QString publisher , QString ISBN , QString language , int pageNum , int available)
{
    this->name = name;
    this->author = author;
    this->subject = subject;
    this->publisher = publisher;
    this->ISBN = ISBN;
    this->language = language;
    this->pageNum = pageNum;
    this->available = available;
}

QString book::get_name()
{
    return this->name;
}

QString book::get_author()
{
    return this->author;
}

QString book::get_subject()
{
    return this->subject;
}

QString book::get_publisher()
{
    return this->publisher;
}

QString book::get_ISBN()
{
    return this->ISBN;
}

QString book::get_language()
{
    return this->language;
}

int book::get_pageNum()
{
    return this->pageNum;
}

int book::get_availNum()
{
    return this->available;
}
