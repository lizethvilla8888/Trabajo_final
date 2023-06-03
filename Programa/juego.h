#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>
#include <QKeyEvent>
#include <QDebug>

#include "comida.h"
#include "cuchillo.h"
#include "personaje.h"
#include "plataforma.h"

class juego : public QGraphicsScene
{
    Q_OBJECT
public:
    juego();
    void paredes_ ();
    void cuchillos_ ();
    void comida_ ();


private:
    float dt;
    personaje *cuerpo;
    cuchillo *cuchi;

    QTimer* timer;
    QList <plataforma *> paredes;
    QList <cuchillo *> *cuchillos;
    QList <comida *> comidas;

    void crear_pared(int x, int y, int ancho, int alto);
    void crear_cuchillos(int Pos_x, int Pos_y);
    void crear_comida (int x, int y, int w_, int h_);
    void AplicarGravedad();

protected:
    void keyPressEvent(QKeyEvent *evento);
private slots:
    void actualizar();
};

#endif // JUEGO_H
