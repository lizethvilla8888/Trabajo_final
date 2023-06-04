#include "personaje.h"

personaje::personaje(int posicionInicialX, int posicionInicialY)
{
    V0 = 50;
    Vx = V0 * cos(Angulo);
    Vy = V0 * sin(Angulo);

    X0 = posicionInicialX;
    Y0 = posicionInicialY;
    setRect(0, 0, 80, 85);
    setPos(X0, Y0);
    posicionX = X0;

   // connect(timer, &QTimer::timeout, this, & personaje::actualizarMParabolico);
    //timerOn();
}

void personaje::saltar()
{
    Y0 = y();
    t = 0;
    timerOn();
}

void personaje::bajar()
{
    t = 10.7;
    timerOn();
}

void personaje::adelantar()
{
    posicionX+=1;
    setPos(posicionX, y());
}

void personaje::timerOn()
{
    timer->start(5);
}

void personaje::timerOff()
{
    timer->stop();
}

float personaje::getPosicionX() const
{
   // posicionX = value;
}

float personaje::getPosicionY() const
{
    //posicionY = value;
}

float personaje::getT() const
{
     return t;
}

void personaje::setY0(float value)
{
    Y0 = value;
    setPos(x(), Y0);
}

void personaje::setPosicionX(float value)
{
    Y0 = value;
    setPos(x(), Y0);
}

void personaje::aplicaraceleracion(QPointF Acel)
{
    float dt=0.1;
    Vx+=dt*Acel.x();
    Vy+=Acel.y();
    posicionX+=Vx*dt+Acel.x()*0.5*dt*dt;
    posicionY+=Vy*dt+Acel.y()*0.5*dt*dt;
    setPos(posicionX,posicionY);
}

QRectF personaje::boundingRect() const
{
    return QRectF(-r,-r,2*r,2*r);
}

void personaje::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
  painter->setBrush(QBrush(Qt:: yellow));
  painter->drawEllipse(boundingRect());
}

personaje::personaje(int r_, int x, int y)
{
    r = r_;
    posx = x;
    posy = y;
    setPos(posx, posy);
}

void personaje::select_sprite(int x, int y)
{

}

void personaje::actualizarMParabolico()
{
    posicionX = X0 + Vx*t;
    posicionY = Y0 - Vy*t + ((G*t*t)/2);
    setPos(posicionX, posicionY);
    t += 0.1;
}
