#ifndef OTHER_H
#define OTHER_H

#include <QGraphicsItem>
#include <QtWidgets>
#include <QPainter>

class Other : public QGraphicsItem
{
public:
    Other(){}
    ~Other(){}

    enum { Type = UserType + 3};
    int type() const {return Type;}
};


#endif // OTHER_H
