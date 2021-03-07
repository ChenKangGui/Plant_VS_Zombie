#ifndef POTATOMINE_H
#define POTATOMINE_H

#include "plant.h"

class PotatoMine : public Plant
{
public:
    PotatoMine();
    void advance(int phase) override;
    QRectF boundingRect()const;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
};

#endif // POTATOMINE_H
