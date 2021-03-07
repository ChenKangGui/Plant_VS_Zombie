#-------------------------------------------------
#
# Project created by QtCreator 2020-12-26T19:12:40
#
#-------------------------------------------------

QT       += core gui multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PlantWar
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    shop.cpp \
    shovel.cpp \
    button.cpp \
    map.cpp \
    mower.cpp \
    card.cpp \
    plant.cpp \
    zombie.cpp \
    sunflower.cpp \
    sun.cpp \
    peashooter.cpp \
    cherrybomb.cpp \
    wallnut.cpp \
    snowpea.cpp \
    potatomine.cpp \
    repeater.cpp \
    pea.cpp \
    basiczombie.cpp \
    conezombie.cpp \
    bucketzombie.cpp \
    screenzombie.cpp \
    footballzombie.cpp

HEADERS  += mainwindow.h \
    shop.h \
    other.h \
    shovel.h \
    button.h \
    map.h \
    mower.h \
    card.h \
    plant.h \
    zombie.h \
    sunflower.h \
    sun.h \
    peashooter.h \
    cherrybomb.h \
    wallnut.h \
    snowpea.h \
    potatomine.h \
    repeater.h \
    pea.h \
    basiczombie.h \
    conezombie.h \
    bucketzombie.h \
    screenzombie.h \
    footballzombie.h

RESOURCES += \
    res.qrc

RC_ICONS += \
    ./res/PVZ.ico
