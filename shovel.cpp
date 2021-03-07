#include "shovel.h"
#include "plant.h"

Shovel::Shovel()
{

}

QRectF Shovel::boundingRect()const
{
    return QRectF(-40, -40, 80, 80);
}

void Shovel::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QRect(-40, -40, 80, 80), QPixmap(":/res/ShovelBank.png"));
    painter->drawPixmap(QRect(-35, -35, 70, 70), QPixmap(":/res/Shovel.png"));
}

void Shovel::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if(QLineF(e->screenPos(), e->buttonDownScenePos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
        return ;
    }
    QDrag *drag = new QDrag(e->widget());
    QMimeData *mime = new QMimeData;
    QImage image(":/res/Shovel.png");
    mime->setText("Shovel");
    mime->setImageData(image);
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image).scaled(70, 70));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Shovel::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ArrowCursor);
}

void Shovel::removePlant(QPointF pos)
{
    QList<QGraphicsItem *> items = scene()->items(pos);
    foreach (QGraphicsItem *item, items)
    {
        if(item->type() == Plant::Type)
        {
            delete item;
            return ;
        }
    }
}









