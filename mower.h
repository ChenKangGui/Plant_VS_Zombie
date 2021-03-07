#ifndef MOWER_H
#define MOWER_H

#include "other.h"

class Mower : public Other
{
public:
    Mower();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void advance(int phase);

    bool flag;
    qreal speed;
};

#endif // MOWER_H
