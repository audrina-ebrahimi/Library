#ifndef OVERLOAD_H
#define OVERLOAD_H

#include <QtCore>
#include "person.h"
#include "book.h"

inline QTextStream & operator << ( QTextStream & out , Person & person)
{
    out << person.get_name() << " " << person.get_pass() << "\n";
    return out;
}

inline QTextStream & operator << ( QTextStream & out , book & books)
{
    out << books.get_ISBN() << " " << books.get_name() << " " << books.get_author() << " " << books.get_subject() << " " << books.get_publisher()
        << " " << books.get_language() << " " << books.get_pageNum() << " " << books.get_availNum() << "\n";
    return out;
}

#endif // OVERLOAD_H
