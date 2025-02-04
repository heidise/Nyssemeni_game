#ifndef GAMEENGINE_HH
#define GAMEENGINE_HH

#include "creategame.hh"
#include "core/logic.hh"

/**
 * @brief The gameEngine class Pelin alulle panija, alustaa pelin.
 * GameEnginessä käsitellään pelin logiikkaa.
 */

class gameEngine
{
public:
    gameEngine();
    ~gameEngine();

    /**
     * @brief initGame Alustaa pelin: luo Logic-olion ja pointterin Cityyn.
     * Kutsuu Logic-olion funktioita, joita tarvitaan pelin alustamiseen.
     */
    void initGame();


private:
    std::shared_ptr<Interface::ICity> city_;
    CourseSide::Logic *logic_;


};

#endif // GAMEENGINE_HH
