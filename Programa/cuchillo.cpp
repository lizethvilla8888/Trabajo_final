#include "cuchillo.h"

cuchillo::cuchillo(int posicionInicialX, int posicionInicialY, int ancho_, int alto_)
{
    posicionX=posicionInicialX;
    posicionY=posicionInicialY;
    ancho = ancho_;
    alto = alto_ ;
    radio = 10;
    setPos(posicionX, posicionY);
}

QRectF cuchillo::boundingRect() const
{
    return QRectF(-radio,-radio,2*radio,2*radio);
}

void cuchillo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::black);
    painter->drawEllipse(boundingRect());
}

float cuchillo::getPosicionX() const
{
    return posicionX;
}

float cuchillo::getPosicionY() const
{
    return posicionY;
}

void cuchillo::aplicaraceleracion(QPointF Acel)
{
    float dt=0.1;
    Vx+=dt*Acel.x();
    Vy+=Acel.y();
    posicionX+=Vx*dt+Acel.x()*0.5*dt*dt;
    posicionY+=Vy*dt+Acel.y()*0.5*dt*dt;
    setPos(posicionX,posicionY);
}
