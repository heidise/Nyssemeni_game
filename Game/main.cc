#include "gameengine.hh"
#include "graphics/simplemainwindow.hh"
#include "dialog.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Q_INIT_RESOURCE(offlinedata);
    gameEngine* engine = new gameEngine;
    engine->initGame();  // Käynnistää pelin.

    return a.exec();
}
