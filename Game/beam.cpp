#include "beam.hh"



Beam::Beam(QGraphicsItem *parent): QObject(), QGraphicsPixmapItem(parent){

    // Asetetaan ammuksen grafiikat.
    setPixmap(QPixmap(":/beam.png").scaled(10,10));

    // Ammus liikkuu tahditetusti.
    moveTimer_ = new QTimer(this);
    connect(moveTimer_,SIGNAL(timeout()),this,SLOT(move()));
    moveTimer_->start(50);
}

Beam::~Beam()
{

}

void Beam::move()
{
    // Asetetaan ammuksen liike.
    int STEP_SIZE = 5;
    double theta = rotation();

    double dy = STEP_SIZE * qSin(qDegreesToRadians(theta));
    double dx = STEP_SIZE * qCos(qDegreesToRadians(theta));

    setPos(x()+dx, y()+dy);

    ++timesMoved_;

    // Kun ammus on liikkunut tarpeeksi monta kertaa, se poistetaan.
    if (timesMoved_ == MAX_TIMES_MOVED){
        moveTimer_->stop();
        delete this;
    }

}

