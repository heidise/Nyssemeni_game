#include <QtTest>

#include "gamestatistics.h"

// Yksikkötestaa GameStatistics-luokan funktioita.

class statisticsTest : public QObject
{
    Q_OBJECT

public:
    statisticsTest();
    ~statisticsTest();

private slots:

    void testInitGameStatictis();

};

statisticsTest::statisticsTest()
{

}

statisticsTest::~statisticsTest()
{

}


void statisticsTest::testInitGameStatictis()
{
    // Tarkistaa, että luoko GameStatistics-luokan funktio initGameStatictis
    // vektorin, jossa jokaisen vektorin arvo on nolla.
    // Pelin aloitustilanteessa jokaisella pelaajalla pitäisi olla pistemääränä
    // eli pistemäärävektorissa nolla.

    GameStatistics statistic;
    statistic.initGameStatictics(4);

    QCOMPARE(statistic.checkPlayerPoints(0), 0);
    QCOMPARE(statistic.checkPlayerPoints(1), 0);
    QCOMPARE(statistic.checkPlayerPoints(2), 0);
    QCOMPARE(statistic.checkPlayerPoints(3), 0);

}



QTEST_APPLESS_MAIN(statisticsTest)

#include "tst_statisticstest.moc"
