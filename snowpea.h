#ifndef SNOWPEA_H
#define SNOWPEA_H

#include "plant.h"

class SnowPea : public Plant
{
public:
    SnowPea();
    void advance(int phase) override;
    bool collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const;
};

#endif // SNOWPEA_H
