#include "playeritem.hh"


PlayerItem::PlayerItem(int x, int y, int type): QObject(), CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type), locHeight_(500)
{
    setPos(mapToParent(x_, y_ ));


}

PlayerItem::~PlayerItem()
{
    
}

QRectF PlayerItem::boundingRect() const
{
    return QRectF(0, 0, 50, 30);
}

void PlayerItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{    
    Q_UNUSED(option);
    Q_UNUSED(widget);

    // Asetetaan pelaajan grafiikat.
    QRectF bounds = boundingRect();
    QImage playerPic(":/player_pic.png");
    painter->drawImage(bounds, playerPic);

}

void PlayerItem::setStartLoc()
{
    location_.setXY(x_, 500-y_);
}


void PlayerItem::setLocation(int x, int y)
{
    if (x == 0){
        location_.setXY(location_.giveX(), locHeight_-y+15);
        locHeight_ = locHeight_-y;
    } else if (y == 0){
        location_.setXY(x_+x+15, location_.giveY());
        x_ = x_ +x;
    }

    this->moveBy(x,y);
}

Interface::Location PlayerItem::getLocation()
{
    return location_;
}

Beam* PlayerItem::setBeam(QPointF targetPosition)
{
    Beam* beam = new Beam();
    beam->setPos(x()+30, y()+30);

    // Asetetaan ammuksen liikkelle linja, jota se seuraa.
    QLineF ln(QPointF(x()+15, y()+15), targetPosition);
    int rotationAngle = -1 * ln.angle();
    beam->setRotation(rotationAngle);

    return beam;
}



