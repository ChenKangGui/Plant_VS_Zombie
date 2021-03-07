#include "card.h"
#include <QDebug>
#include "shop.h"

const QMap<QString, int> Card::map = {{"SunFlower", 0}, \
                                      {"Peashooter", 1}, \
                                      {"CherryBomb", 2}, \
                                      {"WallNut", 3}, \
                                      {"SnowPea", 4}, \
                                      {"PotatoMine", 5}, \
                                      {"Repeater", 6}};
const QVector<QString> Card::name = {"SunFlower", "Peashooter", "CherryBomb", "WallNut", "SnowPea", "PotatoMine", "Repeater"};
const QVector<int> Card::cost = {50, 100, 150, 50, 175, 25, 200};
const QVector<int> Card::cool = {227, 227, 606, 606, 227, 606, 227};


Card::Card(QString s)
{
    text = s;
    counter = 0;
}

QRectF Card::boundingRect() const
{
    return QRectF(-50, -30, 100, 60);
}

void Card::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->scale(0.6, 0.58);
    painter->drawPixmap(QRect(-50, -70, 100, 140), QPixmap(":/res/Card.png"));
    painter->drawPixmap(QRect(-35, -42, 70, 70), QPixmap(":/res/" + text + ".png"));
    QFont font;
    font.setPointSize(15);
    painter->setFont(font);
    painter->drawText(-30, 60, QString().sprintf("%3d", cost[map[text]]));
    if(counter < cool[map[text]])
    {
        QBrush brush(QColor(0, 0, 0, 200));
        painter->setBrush(brush);
        painter->drawRect(QRectF(-48, -68, 98, 132*(1-qreal(counter)/cool[map[text]])));
    }
}

void Card::advance(int phase)
{
    if (!phase)
            return;
    update();
    if (counter < cool[map[text]])
        ++counter;
}

void Card::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
   if(counter < cool[map[text]])
       e->setAccepted(false);
   Shop *shop = qgraphicsitem_cast<Shop *>(parentItem());
   if(cost[map[text]] > shop->sun)
   {
       e->setAccepted(false);
   }
   setCursor(Qt::ArrowCursor);
}

void Card::mouseMoveEvent(QGraphicsSceneMouseEvent *e)
{
    if(QLineF(e->screenPos(), e->buttonDownScreenPos(Qt::LeftButton)).length() < QApplication::startDragDistance())
    {
        return ;
    }

    QImage image(":/res/" + text + ".png");
    QMimeData *mime = new QMimeData();
    mime->setText(text);
    mime->setImageData(image);
    QDrag *drag = new QDrag(e->widget());
    drag->setMimeData(mime);
    drag->setPixmap(QPixmap::fromImage(image));
    drag->setHotSpot(QPoint(35, 35));
    drag->exec();
    setCursor(Qt::ArrowCursor);
}

void Card::mouseReleaseEvent(QGraphicsSceneMouseEvent *)
{
    setCursor(Qt::ArrowCursor);
}










