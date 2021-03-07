#include "button.h"
#include <QDebug>

Button::Button(QSound *s, QTimer *t)
{
    sound = s;
    timer = t;
}

QRectF Button::boundingRect() const
{
    return  QRectF(-80, -20, 160, 40);
}

void Button::paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *)
{
    painter->drawPixmap(QRect(-80, -20, 160, 40), QPixmap(":/res/Button.png"));
    painter->setPen(Qt::green);
    QFont font("Calibri", 18, QFont::Bold, true);
    painter->setFont(font);
    if(timer->isActive())
        painter->drawText(boundingRect(), Qt::AlignCenter, "PAUSE");
    else
        painter->drawText(boundingRect(), Qt::AlignCenter, "CONTINUE");
}

void Button::mousePressEvent(QGraphicsSceneMouseEvent *e)
{
    if(e->button() == Qt::LeftButton)
    {
        if(timer->isActive())
        {
            sound->stop();
            timer->stop();
        }
        else
        {
            sound->play();
            timer->start();
        }
    }
    update();
}







