#include "shop.h"
#include "plant.h"
#include "zombie.h"
#include "sunflower.h"
#include "peashooter.h"
#include "cherrybomb.h"
#include "wallnut.h"
#include "snowpea.h"
#include "repeater.h"
#include "potatomine.h"
#include "sun.h"
#include <QDebug>

Shop::Shop()
{
    sun = 9000;
    counter = 0;
    time = 7.0 * 1000 / 33;
    Card *card = nullptr;
    for(int i=0; i<Card::name.size(); i++)
    {
        card = new Card(Card::name[i]);
        card->setParentItem(this);
        card->setPos(-157+65*i, -2);
    }
}

QRectF Shop::boundingRect() const
{
    return QRectF(-270, -45, 540, 90);
}


void Shop::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QRect(-270, -45, 540, 90), QPixmap(":/res/Shop.png"));
    QFont font;
    font.setPointSize(15);
    painter->setFont(font);
    painter->drawText(QRectF(-255, 18, 65, 22), Qt::AlignCenter, QString::number(sun));
    painter->drawPoint(-220, 0);
}


void Shop::advance(int phase)
{
    if (!phase)
        return;
    update();
    if (++counter >= time)
    {
        counter = 0;
        scene()->addItem(new Sun);
    }
}


void Shop::addPlant(QString s, QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
    {
        if(item->type() == Plant::Type)
        {
            return ;
        }
    }

    sun -= Card::cost[Card::map[s]];
    Plant *plant = nullptr;
    switch(Card::map[s])
    {
        case 0:
            plant = new SunFlower; break;
        case 1:
            plant = new Peashooter; break;
        case 2:
            plant = new CherryBomb;break;
        case 3:
            plant = new WallNut; break;
        case 4:
            plant = new SnowPea; break;
        case 5:
            plant = new PotatoMine; break;
        case 6:
            plant = new Repeater; break;
        default: break;
    }
    plant->setPos(pos);
    scene()->addItem(plant);
    QList<QGraphicsItem *> child = childItems();
    foreach (QGraphicsItem *item, child)
    {
        Card *card = qgraphicsitem_cast<Card *>(item);
        if(card->text == s)
        {
            //card->counter = 0;
        }
    }
    counter = 0;
}






