#ifndef CUCHILLO_H
#define CUCHILLO_H

#include <QGraphicsRectItem>
#include <QObject>
#include <QTimer>
#include <math.h>

#define Angulo (float) 1.22173
#define G (float) 9.81

class cuchillo :   public QObject, public QGraphicsRectItem
{
private:
    QTimer *timer;
    float posicionX;
    float posicionY;
    float X0;
    float Y0;
    float V;
    float V0;
    float Vx;//velocidad en x
    float Vy;//velocidad en y
    float t;
    float delta;

public:
    cuchillo(float posicionInicialX, float posicionInicialY);
    void actulalizarMparabolico();
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
    void calcularVelocidad();
//    double getPosicion_x() const;
//    void setPosicion_x(double value);
//    double getPosicion_y() const;
//    void setPosicion_y(double value);

//    void actualizar_posicion ();

};

#endif // CUCHILLO_H
