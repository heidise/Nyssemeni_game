#ifndef BEAM_HH
#define BEAM_HH

#include <QObject>
#include <QTimer>
#include <QGraphicsItem>
#include <QGraphicsPixmapItem>
#include <QPixmap>
#include <QPainter>
#include <qmath.h>
#include <QDebug>

#include "core/location.hh"

const int MAX_TIMES_MOVED = 3;

/**
 * @brief The Beam class Pelaajan "ammus". Liikkuu ampumisen kohteeseen,
 * mikäli pelaaja on tarpeeksi lähellä kohdetta.
 */
class Beam: public QObject, public QGraphicsPixmapItem
{
    Q_OBJECT
public:
    Beam(QGraphicsItem *parent = 0);
    ~Beam();

public slots:
    /**
     * @brief move Liikuttaa oliota.
     */
    void move();

private:

    // Koordinaatit
    int x_;
    int y_;

    int timesMoved_ = 0;  // Ammus voi liikkua maksimissaan kolme kertaa.

    QTimer *moveTimer_;

};

#endif // BEAM_HH
