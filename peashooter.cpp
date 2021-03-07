#include "peashooter.h"
#include "zombie.h"
#include "pea.h"

Peashooter::Peashooter()
{
    atk = 25;
    hp = 300;
    time = int(1.4 * 1000 / 33);
    setMovie(":/res/Peashooter.gif");
}

void Peashooter::advance(int phase)
{
    if(!phase)
        return ;
    update();

    if(hp < 0)
        delete this;
    else if(++counter >= time)
    {
        counter = 0;
//        if(collidingItems().isEmpty())
        {
            Pea *pea = new Pea(atk);
            pea->setX(x() + 32);
            pea->setY(y());
            scene()->addItem(pea);
            return ;
        }
    }
}

bool Peashooter::collidesWithItem(const QGraphicsItem *other, Qt::ItemSelectionMode mode) const
{
    return other->type()==Zombie::Type && qFuzzyCompare(other->y(), y());
}


