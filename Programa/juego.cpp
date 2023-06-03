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
    paredes_();
    cuchillos_();
    comida_();
    timer = new QTimer;
    connect(timer, SIGNAL(timeout()), this, SLOT(actualizar()));
    timer->start(100);
}

void juego::paredes_()
{
    // 1200,600
    crear_pared(0,523,1300,34);
    //crear_pared(0,0,3,800);
    //crear_pared(1300,0,3,800);
    //crear_pared(0,398,34,700);
    //crear_pared(666,400,34,300);
}

void juego::cuchillos_()
{
    crear_cuchillos(20, 0);
    crear_cuchillos(100,0);
    crear_cuchillos(200, 0);
    crear_cuchillos(300, 0);
}

void juego::comida_()
{
    crear_comida(300,300,50,30);
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

void juego::crear_comida(int x, int y, int w_, int h_)
{
    comidas.push_back(new comida (x,y,w_,h_));
    addItem(comidas.back());
}

void juego::keyPressEvent(QKeyEvent *evento)
{
    if(evento->key()==Qt::Key_D){
        cuerpo->aplicaraceleracion({100,0});
    }
//    for (int i = 0;i < monedas.size();i++) {
//               if(personaje->collidesWithItem(monedas.at(i))){
//                    //puntaje_->incremento(); // incremento de puntaje
//                    removeItem(monedas.at(i));
//                    monedas.removeAt(i);
//                    i--;
//                    }
//            }
//           //Colicion con muros
//           for (int i = 0;i < paredes.size();i++) {
//                if(personaje->collidesWithItem(paredes.at(i))){
//                   personaje->Move_izquierda();
//                }
//           }


    if(evento->key()==Qt::Key_A){
        cuerpo->aplicaraceleracion({-100,0});
    }

    if(evento->key()==Qt::Key_W){
        cuerpo->aplicaraceleracion({0,100});
    }

    if(evento->key()==Qt::Key_S){
      cuerpo->aplicaraceleracion({0,-100});
    }




}

void juego::actualizar()
{
    AplicarGravedad();
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
    cuchillo *Cuchillo_=cuchillos->at(0);
    Cuchillo_->aplicaraceleracion({0,10});
    for(cuchillo *Cuchillo__ : *cuchillos)
    {
        QPointF Pos=Cuchillo__->pos();
        Cuchillo__->aplicaraceleracion({0,10});
    }
}
