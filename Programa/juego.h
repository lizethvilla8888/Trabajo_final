#ifndef JUEGO_H
#define JUEGO_H

#include <QGraphicsScene>
#include <QTimer>
#include <QList>

#include "comida.h"
#include "cuchillo.h"
#include "personaje.h"
#include "plataforma.h"


class juego : public QGraphicsScene
{

public:
    juego();
    void paredes_ ();

private:
    personaje *cuerpo;
    QTimer* timer;
    QList <plataforma *> paredes;
    void crear_pared(int x, int y, int ancho, int alto);

};

#endif // JUEGO_H
