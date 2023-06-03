#include "juego.h"

juego::juego()
{
    // get obtener set modificar
    QBrush l; // imagen de fondo
    QImage r;
    r.load(":/imagenes/WhatsApp Image 2023-05-21 at 2.04.17 AM.jpeg");
    l.setTextureImage(r);
    setBackgroundBrush(l);

<<<<<<< HEAD
    cuerpo = new personaje (700,600);


=======
    cuerpo = new personaje (20,500,500);
>>>>>>> parent of 34a0b32 (cocina)
    cuchillos = new QList<cuchillo*>;

    addItem(cuerpo);
    cuerpo->select_sprite(0,0);
    paredes_();
    cuchillos_();
<<<<<<< HEAD
    comida_();

=======
>>>>>>> parent of 34a0b32 (cocina)
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(100);
}

void juego::paredes_()
{
    crear_pared(0,0,700,34);
    crear_pared(0,0,34,233);
    crear_pared(666,0,34,233);
    crear_pared(0,398,34,700);
    crear_pared(666,400,34,300);
}

void juego::cuchillos_()
{
    crear_cuchillos(20, 0);
    crear_cuchillos(100,0);
    crear_cuchillos(200, 0);
    crear_cuchillos(300, 0);
}

void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes.push_back(new plataforma (x,y,ancho,alto));
    addItem(paredes.back());
}

void juego::crear_cuchillos(int Pos_x, int Pos_y)
{
    int ancho = 15;
    int alto = 15;
    cuchillos->push_back(new cuchillo (Pos_x,Pos_y,ancho, alto));
    addItem(cuchillos->back());
}

void juego::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D){
        cuerpo->aplicaraceleracion({100,0});
    }

    if(evento->key()==Qt::Key_A){
        //cuerpo->();
    }

    if(evento->key()==Qt::Key_W){
        //cuerpo->();
    }

    if(evento->key()==Qt::Key_S){
        //cuerpo->();
    }
<<<<<<< HEAD
=======


>>>>>>> parent of 34a0b32 (cocina)
}

void juego::actualizar()
{
    float random_x = rand()%1200;

    AplicarGravedad();

    for (int i = 0; i < paredes.size(); i++) {
        if (cuerpo->collidesWithItem(paredes.at(i))){
            cuerpo->aplicaraceleracion({0,-10});
        }
        else{
            cuerpo->aplicaraceleracion({0,10});
        }
        for (int j = 0; j < cuchillos->size(); j++) {
            if (paredes[i]->collidesWithItem((*cuchillos)[j])) {
                //cuchillos->(j) = cuerpo->setPosicionX(random_x);
                //QDebug () << "colicion cuchilloa y paredes"<<can ;
            }
        }
    }

}

void juego::AplicarGravedad()
{
    /*QList<QGraphicsItem*> Items = this->items();
    for(QGraphicsItem *Item : Items)
    {
        cuchillo *Cuchillo = dynamic_cast<cuchillo*>(Item);
        if(Cuchillo)
        {
            QPointF Pos=Cuchillo->pos();
            throw 0;
        }
    }*/
    cuerpo->aplicaraceleracion({0,10});
    cuchillo *Cuchillo_ = cuchillos->at(0);
    Cuchillo_->aplicaraceleracion({0,10});
    for(cuchillo *Cuchillo__ : *cuchillos){
        QPointF Pos=Cuchillo__->pos();
        Cuchillo__->aplicaraceleracion({0,10});
    }

}
