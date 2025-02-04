#ifndef CITY_HH
#define CITY_HH

#include "interfaces/icity.hh"
#include "mainwindow.hh"
#include "interfaces/istop.hh"
#include "actors/stop.hh"
#include "actors/nysse.hh"
#include "actors/passenger.hh"
#include "gamestatistics.h"

#include <QTime>
#include <vector>
#include <algorithm>
#include <typeinfo>
#include <QObject>
#include <QtGlobal>

const int NYSSE_TYPE = 1000;
const int PASSENGER_TYPE = 400;
const int STOP_TYPE = 600;

/**
 * @brief The City class Pelin kaupunki, suorittaa pelin tapahtumat.
 */

class City : public QObject, public Interface::ICity
{
    Q_OBJECT

public:
    City();
    ~City();

    /**
     * @brief setMainWindow Asettaa käyttöliittymän pääikkunan.
     * @param window pääikkuna, luodaan tiedostossa creategame.cpp.
     */
    void setMainWindow(MainWindow* window);

    /**
     * @brief addPlayer Lisää pelaajahahmon.
     */
    void addPlayer();

    /**
     * @brief setDialog asettaa aloitusdialogin ja käynnistää sen.
     * @param aloitusdialogi, joka luodaan tiedostossa creategame.cpp.
     */
    void setDialog(Dialog* dialog);

    // ICity interface

    void setBackground(QImage &basicbackground, QImage &bigbackground);
    void setClock(QTime clock);
    void addStop(std::shared_ptr<Interface::IStop> stop);
    void startGame();
    void addActor(std::shared_ptr<Interface::IActor> newactor);
    void removeActor(std::shared_ptr<Interface::IActor> actor);
    void actorRemoved(std::shared_ptr<Interface::IActor> actor);
    bool findActor(std::shared_ptr<Interface::IActor> actor) const;
    void actorMoved(std::shared_ptr<Interface::IActor> actor);
    std::vector<std::shared_ptr<Interface::IActor> > getNearbyActors(Interface::Location loc) const;
    bool isGameOver() const;


public slots:
    void setPlayers(int players);
    void exitGame();

private:

    QTime time_;
    MainWindow *mainW_;

    bool gameIsOver_ = true;  // Onko peli loppunut
    int amountOfPlayers_ = 1;  // Pelaajien määrä

    std::vector<std::shared_ptr<Interface::IActor> > actorsInGame_; // Pelissä olevat Actorit
    std::vector<std::shared_ptr<Interface::IActor>> nysses_;  // Pelin Nysset

};




#endif // CITY_HH
