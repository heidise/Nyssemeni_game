#ifndef GAMESTATISTICS_H
#define GAMESTATISTICS_H

#include <vector>

/**
 * @brief The GameStatistics class Pelin pelaajien pisteiden säilytys- ja muokkausluokka.
 * Mahdollistaa pisteiden lisäämisen pelaajille. Luokassa voidaan tarkastaa, milloin
 * pelin voittoon vaadittava maksimipistemäärä on saavutettu.
 */

class GameStatistics
{
public:
    GameStatistics();

    /**
     * @brief initGameStatictics luo pelin alussa pelaajille pistevektorin,
     * jossa jokaisella pelaajalla on aluksi nolla pistettä.
     * @param players pelaajien lukumäärä.
     */
    void initGameStatictics(int players);

    /**
     * @brief addPoints lisää pelaajalle annetun määrän pisteitä.
     * @param playerNumber vuorossa olevan pelaajan pelaajanumero, jolle lisätään pisteitä.
     * @param points lisättävä pistemäärä.
     */
    void addPoints(int playerNumber, float points);

    /**
     * @brief checkIfWon tarkistaa, onko pelin maksimipistemäärä saavutettu tai ylitetty
     * eli määrittää onko pelaaja voittanut.
     * @param playerNumber pelaajanumero, joka on viimeksi ampunut pelissä.
     * @return true, jos peli on voitettu. False, jos peli jatkuu.
     */
    bool checkIfWon(int playerNumber);

    /**
     * @brief checkPlayerPoints kertoo, paljonko pelaajalla on pisteitä.
     * @param playerNumber pelaajanumero, jonka pisteet halutaan tietää.
     * @param pelaajan pistemäärä.
     */
    float checkPlayerPoints(int playerNumber);

private:
    float max_points_ = 30; // Pelin voittamiseen tarvittava pistemäärä.
    std::vector<float> playerPoints_; // Pelaajien pistemäärät.
};

#endif // GAMESTATISTICS_H
