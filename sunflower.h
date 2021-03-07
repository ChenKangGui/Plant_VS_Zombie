#ifndef SUNFLOWER_H
#define SUNFLOWER_H

#include "plant.h"

class SunFlower : public Plant
{
public:
    SunFlower();

    void advance(int phase);
};

#endif // SUNFLOWER_H
