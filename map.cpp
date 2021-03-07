#include "map.h"
#include <QDebug>

Map::Map()
{
    dragOver = false;
    setAcceptDrops(true);
}
#if 1
QRectF Map::boundingRect()const
{
    return QRectF(-369, -235, 738, 470);
}

void Map::paint(QPainter *p, const QStyleOptionGraphicsItem *, QWidget *)
{
    p->setPen(Qt::black);
    p->drawRect(boundingRect());
}

void Map::dragEnterEvent(QGraphicsSceneDragDropEvent *e)
{
    if(e->mimeData()->hasText())
    {
        e->setAccepted(true);
        dragOver = true;
        update();
    }
    else
        e->setAccepted(false);
}

void Map::dragLeaveEvent(QGraphicsSceneDragDropEvent *)
{
    dragOver = false;
    update();
}

void Map::dropEvent(QGraphicsSceneDragDropEvent *e)
{
    dragOver = false;
    if(e->mimeData()->hasText())
    {
        QString s = e->mimeData()->text();
        QPointF pos = mapToScene(e->pos());
        pos.setX((int(pos.x()) - 249) / 82 * 82 + 290);
        pos.setY((int(pos.y()) - 81) / 98 * 98 + 130);
        if(s == "Shovel")
        {
            Shovel *shovel = qgraphicsitem_cast<Shovel *>(scene()->items(QPointF(830, 15))[0]);
            shovel->removePlant(pos);
        }
        else
        {
            Shop *shop = qgraphicsitem_cast<Shop *>(scene()->items(QPointF(300, 15))[0]);
            shop->addPlant(s, pos);
        }
    }
    update();
}
#endif

