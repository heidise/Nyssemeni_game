#include "city.hh"

#include <QDebug>

City::City()
{
}

City::~City()
{

}

void City::setMainWindow(MainWindow* window)
{
    mainW_ = window;
    connect(mainW_, SIGNAL(exitFromMainwindow()), this, SLOT(exitGame()));
}


void City::setBackground(QImage &basicbackground, QImage &bigbackground)
{
    Q_UNUSED(bigbackground);

    mainW_->setPicture(basicbackground);

}

void City::setClock(QTime clock)
{
   if (clock.isValid() == true) {
       time_ = clock;
   }

   else {
       qDebug() << "Aika on virheellinen";
   }
}

void City::addStop(std::shared_ptr<Interface::IStop> stop)
{
    // Pysäkki lisätään käyttöliittymään.
    Interface::Location stopLoc = stop->getLocation();
    mainW_->addActor(stopLoc.giveX(), 500-stopLoc.giveY(), STOP_TYPE);
}

void City::startGame()
{
    gameIsOver_ = false;

    // Lisätään käyttäjän aloitusdialogissa määritettävän lukumäärän verran pelaajia peliin.
    int players = amountOfPlayers_;
    while (players != 0) {
        addPlayer();
        players = players - 1;
    }

    mainW_->setScoreTable();
    mainW_->setStartingPlayer();
    mainW_->show();

}

void City::addActor(std::shared_ptr<Interface::IActor> newactor)
{
    Interface::Location actorLoc = newactor->giveLocation();

    // Uuden Actorin tyyppi määritellään, ja lisätään käyttöliittymään.
    // Tyyppejä on kaksi: matkustaja (Passenger-olio), ja nysse (Nysse-olio).

    if (dynamic_cast<CourseSide::Passenger*>(newactor.get()) != 0){
        mainW_->setActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, PASSENGER_TYPE);
    } else if (dynamic_cast<CourseSide::Nysse*>(newactor.get()) != 0){
        mainW_->setActor(newactor);
        mainW_->addActor(actorLoc.giveX()-5, 500-actorLoc.giveY()-5, NYSSE_TYPE);
        nysses_.push_back(newactor);
    } else {
        return;
    }

    mainW_->addToMap();
    actorsInGame_.push_back(newactor);  // Uusi Actor lisätään vektoriin, joka sisältää aktiiviset Actorit.

}

void City::removeActor(std::shared_ptr<Interface::IActor> actor)
{
    // Tarkastetaan, onko Actor pelissä.
    std::vector<std::shared_ptr<Interface::IActor>>::iterator it;
    it = std::find(actorsInGame_.begin(), actorsInGame_.end(), actor);

    if (it != actorsInGame_.end()){
        // Actor poistetaan pelistä.
        for (auto a: actorsInGame_){
            if (a == actor){
                actorsInGame_.erase((std::remove(actorsInGame_.begin(), actorsInGame_.end(), actor), actorsInGame_.end()));
                mainW_->removeActorItem(actor);
                actor->remove();
            }
        }
    } else {
        qDebug("Actor ei ole pelissä.");
    }

}

void City::actorRemoved(std::shared_ptr<Interface::IActor> actor)
{
    Q_UNUSED(actor);
}

bool City::findActor(std::shared_ptr<Interface::IActor> actor) const
{
    for (auto a: actorsInGame_){
        if (a == actor){
            return true;
        }
    }

    return false;
}

void City::actorMoved(std::shared_ptr<Interface::IActor> actor)
{
    // Liikuttaa Actoria pääikkunassa.
    mainW_->moveActorItem(actor);
}

std::vector<std::shared_ptr<Interface::IActor> > City::getNearbyActors(Interface::Location loc) const
{
    std::vector<std::shared_ptr<Interface::IActor>> nearbyActors; // Hyökkäyksen kohteet.
    int limit = 67; // Kuinka lähellä pelaajan on oltava, jotta hyökkäys on onnistunut.

    for (auto b: nysses_){
        if (b->giveLocation().isClose(loc, limit) == true){
            nearbyActors.push_back(b);
        }
    }

    return  nearbyActors;
}

bool City::isGameOver() const
{
    return gameIsOver_;
}

void City::setPlayers(int players)
{
    amountOfPlayers_ = players;
}

void City::exitGame()
{
    // Suljetaan peli.
    exit(0);
}

void City::addPlayer()
{
    // Kaikkien pelaajien lähtöasema on origo.
    mainW_->addPlayer(0,0,0);
}

void City::setDialog(Dialog* dialog)
{
    // Avataan aloitusdialogi ja yhdistetään sen signaalit ja slotit.
    connect(dialog, SIGNAL(numberOfPlayers(int)), this, SLOT(setPlayers(int)));
    connect(dialog, SIGNAL(playerNames(QString, QString, QString, QString)),
            mainW_, SLOT(setPlayerNames(QString, QString, QString, QString)));
    connect(dialog, SIGNAL(exitFromDialog()), this, SLOT(exitGame()));

    dialog->exec();

}





