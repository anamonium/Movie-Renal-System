QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addmovie.cpp \
    administrator.cpp \
    login.cpp \
    main.cpp \
    mainwindow.cpp \
    movie.cpp \
    movielist.cpp \
    movielistcategory.cpp \
    moviesearch.cpp \
    myexception.cpp \
    signin.cpp \
    user.cpp \
    userlist.cpp

HEADERS += \
    addmovie.h \
    administrator.h \
    login.h \
    mainwindow.h \
    movie.h \
    movielist.h \
    movielistcategory.h \
    moviesearch.h \
    myexception.h \
    person.h \
    signin.h \
    user.h \
    userlist.h

FORMS += \
    addmovie.ui \
    administrator.ui \
    login.ui \
    mainwindow.ui \
    movielist.ui \
    movielistcategory.ui \
    moviesearch.ui \
    signin.ui \
    user.ui \
    userlist.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
