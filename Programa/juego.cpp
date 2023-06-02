#include "juego.h"

juego::juego()
{
    QBrush l; // imagen de fondo
    QImage r;
    r.load(":/imagenes/WhatsApp Image 2023-05-21 at 2.04.17 AM.jpeg");
    l.setTextureImage(r);
    setBackgroundBrush(l);

    cuerpo = new personaje (20,30,30);

    addItem(cuerpo);
    cuerpo->select_sprite(0,0);
    paredes_();
    timer = new QTimer(this);
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(16);
}

void juego::paredes_()
{
    crear_pared(0,0,700,34);
    crear_pared(0,0,34,233);
    crear_pared(666,0,34,233);
    crear_pared(0,398,34,700);
    crear_pared(666,400,34,300);
}

void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes.push_back(new plataforma (x,y,ancho,alto));
    addItem(paredes.back());
}
