#ifndef COMIDA_H
#define COMIDA_H

#include <QGraphicsItem>
#include <QPainter>
#include <vector>



class comida :public QGraphicsRectItem
{
    int w,h;
    int posx, posy;
public:
    comida(int x, int y,int w_, int h_);
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
};

#endif // COMIDA_H
