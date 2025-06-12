QT       += core gui sql
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

SOURCES += \
    main.cpp \
    gameboard.cpp \
    aiplayer.cpp \
    new.cpp \
    user.cpp \
    gamehistory.cpp \
    mainwindow.cpp

HEADERS += \
    gameboard.h \
    aiplayer.h \
    gamehistory.h \
    user.h \
    gamehistory.h \
    mainwindow.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
