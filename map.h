#ifndef MAP_H
#define MAP_H

#include "other.h"
#include "shop.h"
#include "shovel.h"
#include <QGraphicsSceneDragDropEvent>



class Map : public Other
{
public:
    Map();

    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void dragEnterEvent(QGraphicsSceneDragDropEvent *);
    void dragLeaveEvent(QGraphicsSceneDragDropEvent *);
    void dropEvent(QGraphicsSceneDragDropEvent *);

    bool dragOver;
};

#endif // MAP_H
