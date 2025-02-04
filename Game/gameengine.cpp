#include "gameengine.hh"

gameEngine::gameEngine()
{

}

void gameEngine::initGame()
{

   city_ = Interface::createGame();

   // Luodaan Logic-olio ja kutsutaan pelin alustamiseen tarvittavia funktioita.
   logic_ = new CourseSide::Logic;

   logic_->fileConfig();
   logic_->takeCity(city_);
   logic_->finalizeGameStart();


}
