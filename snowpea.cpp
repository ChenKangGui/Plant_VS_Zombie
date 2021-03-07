#include "snowpea.h"
#include "zombie.h"
#include "pea.h"

SnowPea::SnowPea()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/res/SnowPea.gif");
}

void SnowPea::advance(int phase)
{
    if(!phase)
        return ;
    update();
    if(hp <= 0)
    {
        delete this;
    }
    else if(++counter >= time)
    {
        counter = 0;
//        if(collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk, true);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return ;
        }
    }
}

bool SnowPea::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode ) const
{
    return other->Type==Zombie::Type && qFuzzyCompare(other->y(), y());
}


