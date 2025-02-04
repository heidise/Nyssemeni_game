#ifndef NYSSEITEM_HH
#define NYSSEITEM_HH

#include "graphics/simpleactoritem.hh"

/**
 * @brief The NysseItem class IVehicle-rajapinnasta periytettyä Nysse-Actoria vastaava graafinen toteutus.
 */

class NysseItem: public QObject, public CourseSide::SimpleActorItem
{
    Q_OBJECT
public:
    NysseItem(int, int, int);
    ~NysseItem();

public:

    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);

    /**
     * @brief changeColor Vaihtaa NysseItemin värin sinisestä punaiseen.
     */
    void changeColor();

private:
    int x_;
    int y_;
    int type_;
    QBrush brush_;
    bool colorChanged_;  // Onko väriä muutettu; onko pelaaja ampunut Nyssen.
};

#endif // NYSSEITEM_HH
