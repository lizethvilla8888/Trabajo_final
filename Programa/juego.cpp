#include "juego.h"

juego::juego()
{
    // get obtener set modificar
    QBrush l; // imagen de fondo
    QImage r;
    r.load(":/imagenes/cocina.jpg");
    l.setTextureImage(r);
    setBackgroundBrush(l);
    //cuchi=new cuchillo(100,100);

    cuerpo = new personaje (20,700,600);
    cuchillos = new QList<cuchillo*>;
    addItem(cuerpo);

    gane = new ganaste;
    perdi = new perdio;

    paredes_();
    cuchillos_();


    comida_();

    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(50);

    timer_1_colici = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(colision_cuchillos()));
    timer_1_colici->start(15);
}

juego::~juego()
{
    delete gane;
    delete perdi;
    delete cuerpo;
}

void juego::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D){
        cuerpo->aplicaraceleracion({100,0});
    }

    if(evento->key()==Qt::Key_A){
        cuerpo->aplicaraceleracion({-100,0});
    }

    if(evento->key()==Qt::Key_W){
        cuerpo->aplicaraceleracion({0,-100});
    }

    if(evento->key()==Qt::Key_S){
      cuerpo->aplicaraceleracion({0,100});
    }
}

void juego::actualizar()
{
    AplicarGravedad();
}

void juego::colision_cuchillos()
{
    for (int j = 0; j < cuchillos->size(); j++) {
        //if (paredes[i]->collidesWithItem((*cuchillos)[j]))
        cuchillo *cuchilloActual = (*cuchillos)[j];
        if (cuchilloActual->getPosicionY()>700 && cuchilloActual->getPosicionX() != 0){
            cuchillos->removeAt(j);
            cuchillos_();
            qDebug() << "Cantidad de cuchillos:" << cuchillos->size();
        }

    }
//        cuchillo *Cuchillo_=cuchillos->at(0);
//        Cuchillo_->aplicaraceleracion({0,10});
//        for(cuchillo *Cuchillo__ : *cuchillos)
//        {
//            QPointF Pos=Cuchillo__->pos();
//            Cuchillo__->aplicaraceleracion({0,10});
//        }

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
    cuerpo->aplicaraceleracion({0,7});

    for (cuchillo *Cuchillo__ : *cuchillos){
        //QPointF Pos = Cuchillo__->pos();
        Cuchillo__->aplicaraceleracion({0, 60});
    }
         //   qDebug ()<< "aceleracion aplicada";
}

void juego::crear_pared(int x, int y, int ancho, int alto)
{
    paredes.push_back(new plataforma (x,y,ancho,alto));
    addItem(paredes.back());
}

void juego::crear_cuchillos(int Pos_x, int Pos_y)
{
    int ancho = 1;
    int alto = 1;
    cuchillos->push_back(new cuchillo (Pos_x,Pos_y,ancho, alto));
    addItem(cuchillos->back());
}

void juego::crear_comida(int x, int y, int w_, int h_)
{
    comidas.push_back(new comida (x,y,w_,h_));
    addItem(comidas.back());
}

void juego::paredes_()
{
    // 1200,600
    crear_pared(0,523,1300,34);
    crear_pared(254,406,100,10);
    crear_pared(413,300,100,10);
    crear_pared(837,311,100,10);
    crear_pared(666,400,100,10);
}

void juego::cuchillos_()
{
    int random_num;
    random_num = rand()%700;
    crear_cuchillos(random_num,0);

   // qDebug () << "cuerpo agregado a lista";


}

void juego::comida_()
{
    crear_comida(300,380,20,20);
    crear_comida(459,276,20,20);
    crear_comida(883,285,20,20);
    crear_comida(712,374,20,20);

//    crear_comida(300,380,20,20);
//    crear_comida(367,276,20,20);
//    crear_comida(791,285,20,20);
//    crear_comida(620,374,20,20);
}
