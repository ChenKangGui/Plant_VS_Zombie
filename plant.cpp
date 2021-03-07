#include "plant.h"
#include <QDebug>
#include "zombie.h"

Plant::Plant()
{
    movie = NULL;
    atk = counter = state = time = 0;
}

QRectF Plant::boundingRect() const
{
    return QRectF(-35, -35, 70, 70);
}

void Plant::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawImage(boundingRect(), movie->currentImage());
}

bool Plant::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode ) const
{
    return other->type() == Zombie::Type && qFuzzyCompare(other->y(), y()) && qAbs(other->x() - x()) < 30;
}

int Plant::type() const
{
    return Type;
}

void Plant::setMovie(QString path)
{
    if(movie)
        delete movie;
    movie = new QMovie(path);
    movie->start();
}











