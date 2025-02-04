#ifndef MAINWINDOW_HH
#define MAINWINDOW_HH

#include <QMainWindow>
#include <QCommonStyle>
#include <QTime>

#include "graphics/simplemainwindow.hh"
#include "graphics/simpleactoritem.hh"
#include "playeritem.hh"
#include "dialog.h"
#include "beam.hh"
#include "gameengine.hh"
#include "nysseitem.hh"
#include "gamestatistics.h"
#include "winnerdialog.h"


#include <vector>
#include <map>
#include <algorithm>

const int NYSSE = 1000;

namespace Ui {
class MainWindow;
}

/**
 * @brief The MainWindow class Pelin käyttöliitymä.
 */

class MainWindow : public CourseSide::SimpleMainWindow
{
    std::shared_ptr<Interface::ICity> gameArea_;

    Q_OBJECT

public:
    explicit MainWindow(std::shared_ptr<Interface::ICity>, QWidget *parent = 0);
    ~MainWindow();

    void addActor(int locX, int locY, int type);

    /**
     * @brief Asettaa taustakuvan
     * @param img taustakuva, saadaan Citystä.
     */
    void setPicture(QImage &img);

    /**
     * @brief moveActorItem liikuttaa actorItemeitä peli-ikkunassa.
     * @param actorToBeMoved actor, jota vastaavaa actorItemiä liikutetaan.
     */
    void moveActorItem(std::shared_ptr<Interface::IActor> actorToBeMoved);

    /**
     * @brief setActor Asettaa attribuutin lastAc_ arvoksi viimeisimmän lisätyn actorin.
     * @param newac viimeisin lisätty actor, saadaan Citystä.
     */
    void setActor(std::shared_ptr<Interface::IActor> newac);

    /**
     * @brief addToMap Lisää parin actors_-mappiin, pari arvot ovat
     * key; lastAc_, ja value; *lastItem_.
     */
    void addToMap();

    /**
     * @brief removeActorItem Poistaa alkion actors_-mapista.
     * @param actorToBeRemoved elementin key-arvo, saadaan Citystä.
     */
    void removeActorItem(std::shared_ptr<Interface::IActor> actorToBeRemoved);

    /**
     * @brief addPlayer Lisää playerItemin peli-ikkunaan ja players_-vektoriin.
     * @param locX Aloitusaseman x-koordinaatti.
     * @param locY Aloitusaseman y-koordinaatti.
     * @param type itemin tyyppi.
     */
    void addPlayer(int locX, int locY, int type);

    /**
     * @brief checkPlayerMovement tarkistaa, että pelaaja liikkuu peli-ikkunan sisällä.
     */
    void checkPlayerMovement();

    /**
     * @brief setStartingPlayer asettaa pelin alussa aloituspelaajan.
     */
    void setStartingPlayer();

    /**
     * @brief setScoreTable luo pelin alussa GameStatistics olion, johon pelaajien pisteet kerätään.
     * Päivittää Mainwindowiin pelaajalukumäärän mukaisesti pelaajien pisteet.
     */
    void setScoreTable();

    /**
     * @brief updateScoreTable päivittää Mainwindowiin pelaajien pisteet näkyville.
     */
    void updateScoreTable();

    /**
     * @brief shootTarget suorittaa ampumisen seuraukset.
     */
    void shootTarget(std::vector<std::shared_ptr<Interface::IActor> > actorsInRange);

    /**
     * @brief gameIsWon kutsutaan, kun joku pelaajista on voittanut pelin.
     * gameIsWon luo loppudialogin WinnerDialog ja käynnistää sen.
     */
    void gameIsWon();


signals:
    void exitFromMainwindow();

public slots:

    void setPlayerNames(QString name1, QString name2, QString name3, QString name4);


private slots:

    void on_moveRightBtn_clicked();

    void on_moveLeftBtn_clicked();

    void on_moveDownBtn_clicked();

    void on_moveUpBtn_clicked();

    void on_shootButton_clicked();

    void on_newgameButton_clicked();

    void on_exitButton_clicked();

private:

    /**
     * @brief removePassengersfromNysse poistaa Passengerit osuman saaneesta Nyssestä.
     * @param nysse Nysse, josta Passengeri poistetaan.
     * @return poistettujen Passengereiden lukumäärä.
     */
    float removePassengersfromNysse(std::shared_ptr<Interface::IActor> nysse);

    /**
     * @brief isAnyActorNear Tarkistaa, onko playerItemin lähellä ammuttavia kohteita.
     * @param size vektorin, jossa ammuttavat kohteet on, koko.
     * @return true, jos vektori ei ole tyhjä, muulloin false.
     */
    bool isAnyActorNear(int size);

    // Attribuutit

    Ui::MainWindow *ui;
    QGraphicsScene *map;
    QTimer *timer;
    QPalette hitLabelPal_;  // Ilmoittaa, osuiko pelaaja kohteeseen.
    QTime time_;

    Beam* beam_; // Pelaajan "ammus".

    GameStatistics *statistics_;

    PlayerItem* currentPlayer_; // Vuorossa oleva pelaaja (PlayerItem).
    std::vector<PlayerItem*> players_; // Pelissä olevat pelaajat (PlayerItem).
    std::vector<QString> playerNames_; // Pelaajien nimet.

    CourseSide::SimpleActorItem *lastItem_;  // Viimeisimmäksi lisätty ActorItem.
    std::shared_ptr<Interface::IActor> lastAc_;  // Viimeisimmäksi lisätty Actor.

    std::vector<NysseItem*> nysses_;
    std::map<std::shared_ptr<Interface::IActor>, CourseSide::SimpleActorItem*> actors_;  // Sisältää Actorin ja sitä vastaavan ActorItemin.

    int turn_; // Vuorossa olevan pelaajan numero, pelaaja1 = 0, pelaaja2 = 1,...
    int numberofplayers_; // Pelaajien kokonaislukumäärä.

    float nyssePoint_ = 0.5; // Bussin ampumisesta saavata pistemäärä.
    float passengerPoint_ = 1;

    int width_ = 500; //pxls
    int height_ = 500;
    int tick_ = 500; //ms    


};

#endif // MAINWINDOW_HH
