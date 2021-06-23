QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addbook.cpp \
    addgroup.cpp \
    admindashboard.cpp \
    book.cpp \
    boydashboard.cpp \
    boyget.cpp \
    choose_gender.cpp \
    closeboy.cpp \
    closegirl.cpp \
    deletebook.cpp \
    editbook.cpp \
    editgroup.cpp \
    girlget.cpp \
    groupbooks.cpp \
    log_in.cpp \
    main.cpp \
    mainwindow.cpp \
    person.cpp \
    preedit.cpp \
    returnboy.cpp \
    returngirl.cpp \
    sign_up.cpp \
    situation.cpp \
    userdashboard.cpp \
    view_booklist.cpp \
    viewboy.cpp \
    viewgirl.cpp \
    viewmember.cpp

HEADERS += \
    addbook.h \
    addgroup.h \
    admindashboard.h \
    book.h \
    boydashboard.h \
    boyget.h \
    choose_gender.h \
    closeboy.h \
    closegirl.h \
    deletebook.h \
    editbook.h \
    editgroup.h \
    girlget.h \
    groupbooks.h \
    log_in.h \
    mainwindow.h \
    overload.h \
    person.h \
    preedit.h \
    returnboy.h \
    returngirl.h \
    sign_up.h \
    situation.h \
    userdashboard.h \
    view_booklist.h \
    viewboy.h \
    viewgirl.h \
    viewmember.h

FORMS += \
    addbook.ui \
    addgroup.ui \
    admindashboard.ui \
    boydashboard.ui \
    boyget.ui \
    choose_gender.ui \
    closeboy.ui \
    closegirl.ui \
    deletebook.ui \
    editbook.ui \
    editgroup.ui \
    girlget.ui \
    groupbooks.ui \
    log_in.ui \
    mainwindow.ui \
    preedit.ui \
    returnboy.ui \
    returngirl.ui \
    sign_up.ui \
    situation.ui \
    userdashboard.ui \
    view_booklist.ui \
    viewboy.ui \
    viewgirl.ui \
    viewmember.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Photos.qrc \
    font.qrc \
    icons.qrc

DISTFILES +=
