#include "screenzombie.h"

ScreenZombie::ScreenZombie()
{
    hp = 1370;
    atk = 100 * 33 / 1000;
    speed = 80.0 * 33 / 1000 / 4.7;
    setMovie(":/res/ScreenZombieWalk.gif");
}

void ScreenZombie::advance(int phase)
{
    if(!phase)
    {
        return ;
    }
    update();

    if(hp <= 0)
    {
        if(state != 2)
        {
            state = 2;
            setMovie(":/res/ZombieDie.gif");
            setHead(":/res/ZombieHead.gif");
        }
        else if(movie->frameCount()-1 == movie->currentFrameNumber())
            delete this;
        return ;
    }

    QList<QGraphicsItem *> items = collidingItems();
    if(!items.isEmpty())
    {
        Plant *plant = qgraphicsitem_cast<Plant *>(items[0]);
        plant->hp -= atk;
        if(state != 1)
        {
            state = 1;
            setMovie(":/res/ScreenZombieAttack.gif");
        }
        return ;
    }

    if(state)
    {
        state = 0;
        setMovie(":/res/ScreenZombieWalk.gif");
    }
    setX(x() - speed);
}
