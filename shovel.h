#ifndef SHOVEL_H
#define SHOVEL_H

#include "other.h"

class Shovel : public Other
{
public:
    Shovel();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *w)override;
    void mousePressEvent(QGraphicsSceneMouseEvent *e) override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *e)override;
    void removePlant(QPointF pos);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *);

};

#endif // SHOVEL_H
