#include "cuchillo.h"


//cuchillo::cuchillo(float posicionInicialX, float posicionInicialY)
//{
//    //V = v;
//    V0 = 78;
//    Vx = V0 * cos(Angulo);
//    Vy = V0 * sin(Angulo);

//    X0 = posicionInicialX;
//    Y0 = posicionInicialY;

//    //delta = del ;

//    setRect(0, 0, 10, 10);
//    setPos(X0, Y0);

//    connect(timer, &QTimer::timeout, this, &cuchillo::actulalizarMparabolico);
//    timer->start(15);
//}

//void cuchillo::actulalizarMparabolico()
//{
//    posicionX = X0 - Vx*t;
//    posicionY = Y0 - Vy*t + ((G*t*t)/2);
//    setPos(posicionX, posicionY);
//    t += 0.1;
//}

//QRectF cuchillo::boundingRect() const
//{
//    return QRectF(-radio,-radio,2*radio,2*radio);
//}

//void cuchillo::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
//{
//    painter->setBrush(Qt::yellow);
//    painter->drawEllipse(boundingRect());
//}

//void cuchillo::calcularVelocidad()
//{
//    Vx = v*cos(angulo);
//   // Vy = v*sin(angulo)-G*del;
//    angulo = atan2(Vy,Vx);
//    v = sqrt(Vx*velocidad_x+Vy*Vy);
//}
