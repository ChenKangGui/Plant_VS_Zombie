#ifndef CARD_H
#define CARD_H

#include "other.h"

class Card : public Other
{
public:
    Card(QString s);

    int counter;
    QString text;
    const static QMap<QString, int> map;
    const static QVector<QString> name;
    const static QVector<int> cost;
    const static QVector<int> cool;
    QRectF boundingRect() const override;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *, QWidget *);
    void advance(int phase) override;
    void mousePressEvent(QGraphicsSceneMouseEvent *)override;
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *)override;
    void mouseMoveEvent(QGraphicsSceneMouseEvent *)override;

};

#endif // CARD_H
