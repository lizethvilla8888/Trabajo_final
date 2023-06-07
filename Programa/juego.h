#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QDebug>
#include <random>
#include <iostream>

#include "ganaste.h"
#include "perdio.h"

#include "comida.h"
#include "cuchillo.h"
#include "personaje.h"
#include "plataforma.h"

using namespace std;

class juego : public QGraphicsScene
{
    Q_OBJECT
public:
    juego();
    void paredes_ ();
    void cuchillos_ ();
    void comida_();

    personaje *cuerpo;

private:
    float dt;
    void AplicarGravedad();

    QTimer* timer,*timer_1_colici;
    QList <plataforma *> *paredes;
    QList<comida *> *monedas;
    QList <cuchillo *> *cuchillos;

    QList<comida *> eliminarMonedas(QList<comida *> monedas,int pos);
    void crear_pared(int x, int y, int ancho, int alto);
    void crear_monedas (int x, int y, int ancho, int alto);
    void crear_cuchillos(int Pos_x, int Pos_y);

protected:
    void keyPressEvent(QKeyEvent *evento);

private slots:
    void actualizar();
    void colision_cuchillos();
};

#endif // JUEGO_H
