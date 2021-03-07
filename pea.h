#ifndef PEA_H
#define PEA_H

#include "other.h"

class Pea : public Other
{
public:
    Pea(int attack, bool flag = false);
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
    void advance(int phase) override;

    bool snow;
    int atk;
    qreal speed;
};

#endif // PEA_H
