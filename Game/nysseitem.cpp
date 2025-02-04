#include "nysseitem.hh"

NysseItem::NysseItem(int x, int y, int type): CourseSide::SimpleActorItem(x, y, type), x_(x), y_(y), type_(type)
{
    setPos(mapToParent(x_, y_));
    colorChanged_ = false;
}

NysseItem::~NysseItem()
{

}


QRectF NysseItem::boundingRect() const
{
    return QRectF(0, 0, 20, 15);

}

void NysseItem::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    Q_UNUSED(option);
    Q_UNUSED(widget);

    QRectF bounds = boundingRect();

    //Piirretään Nysse

    if (colorChanged_){
        QColor color(Qt::red);
        QBrush brush(color);
        painter->setBrush(brush);
        painter->drawRect(bounds);
    } else {
         QColor color(Qt::blue);
         QBrush brush(color);
         painter->setBrush(brush);
         painter->drawRect(bounds);
    }

}

void NysseItem::changeColor()
{
    colorChanged_ = true;
    update();


}
