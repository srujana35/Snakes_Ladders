QT       += core gui\
            multimedia

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    finished.cpp \
    game.cpp \
    main.cpp \
    introduction.cpp \
    player.cpp \
    playerintroduction.cpp \
    scoreboard.cpp \
    tile.cpp

HEADERS += \
    finished.h \
    game.h \
    introduction.h \
    player.h \
    playerintroduction.h \
    scoreboard.h \
    tile.h

FORMS += \
    finished.ui \
    game.ui \
    introduction.ui \
    playerintroduction.ui \
    scoreboard.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    images.qrc \
    sounds.qrc

DISTFILES += \
    sounds/Shake And Roll Dice-SoundBible.com-591494296.mp3
