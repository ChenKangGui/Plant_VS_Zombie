#ifndef PEASHOOTER_H
#define PEASHOOTER_H

#include "plant.h"

class Peashooter : public Plant
{
public:
    Peashooter();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
};

#endif // PEASHOOTER_H
