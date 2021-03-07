#include "repeater.h"

#include "zombie.h"
#include "pea.h"

Repeater::Repeater()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/res/Repeater.gif");
}

void Repeater::advance(int phase)
{
    if(!phase)
    {
        return ;
    }
    update();

    if(hp <= 0)
    {
        delete this;
    }
    else if(++counter >= time)
    {
        counter = 0;
//        if (!collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            pea = new Pea(atk);
            pea->setX(x() + 64);
            pea->setY(y());
            scene()->addItem(pea);
            pea = new Pea(atk);
            pea->setX(x() + 96);
            pea->setY(y());
            scene()->addItem(pea);
            return ;
        }
    }
}

bool Repeater::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Zombie::Type && qFuzzyCompare(other->y(), y());
}


