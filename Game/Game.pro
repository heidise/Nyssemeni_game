TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

SOURCES += \
    beam.cpp \
    city.cpp \
    creategame.cpp \
    dialog.cpp \
    gameengine.cpp \
    gamestatistics.cpp \
    mainwindow.cpp \
    nysseitem.cpp \
    playeritem.cpp \
    main.cc\
    winnerdialog.cpp


win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a

HEADERS += \
    beam.hh \
    city.hh \
    dialog.h \
    gameengine.hh \ \
    gamestatistics.h \
    mainwindow.hh \
    nysseitem.hh \
    playeritem.hh \ \
    winnerdialog.h

FORMS += \
    dialog.ui \
    mainwindow.ui \
    winnerdialog.ui
    gameengine.hh \

RESOURCES += \
    beam.png\
    background.jpg\
    player_pic.png\
    winner_background.jpg\
