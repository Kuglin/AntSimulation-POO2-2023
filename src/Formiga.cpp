#include "Formiga.h"
#include "FuncoesAuxiliares.h"

#include <cmath>
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#define PI 3.14159265

Formiga::Formiga(int x, int y, int w, int h, float vel, int angulo_inicial) : Objeto(x, y, w, h){

    velocidade = vel;

    dir_x = 0;
    dir_y = 0;

    angulo = angulo_inicial;
    aceleracao_angular = ((rand() % 3)-1);

}

void Formiga::girar_vetor(int ang) {

    angulo = int(angulo + ang) % 360;

    dir_x = velocidade * cos(angulo * PI/180);
    dir_y = velocidade * sin(angulo * PI/180);
}

void Formiga::girar_aleatorio() {

    if ((gerar_random(0,100)) == 0)
        aceleracao_angular = gerar_random(-1,1);

    girar_vetor(aceleracao_angular);

}

void Formiga::mover_dir() {

    move_x(dir_x);
    move_y(dir_y);
    
}

void Formiga::move_x(float v) {

    pos_x += v;
    rect.x = pos_x;

}

void Formiga::move_y(float v) {

    pos_y += v;
    rect.y = pos_y;

}



bool Formiga::verf_colisao(Objeto *obj) {

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = obj->get_pos_x();
    rightA = obj->get_pos_x() + obj->get_width();
    topA = obj->get_pos_y();
    bottomA = obj->get_pos_y() + obj->get_height();

    leftB = pos_x + dir_x;
    rightB = pos_x + width + dir_x;
    topB = pos_y + dir_y;
    bottomB = pos_y + height + dir_y;

    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    return 1;
}

void Formiga::draw(Renderer *r){
    
    r->drawRect(&rect);
    r->drawLine(pos_x + width/2, 
    pos_y + height/2, 
    pos_x + width/2 + dir_x * width ,
    pos_y + height/2 + dir_y * height);

}

// void Formiga::visao(Objeto *comida, Renderer *r) {

//     int leftA, leftB;
//     int rightA, rightB;
//     int topA, topB;
//     int bottomA, bottomB;

//     Objeto *obj1 = new Objeto(pos_x -(areaVisao/2) + width/2 + dir_x * width * distVisao, 
//                               pos_y -(areaVisao/2) + height/2 + dir_y * height * distVisao, 
//                               areaVisao, 
//                               areaVisao);

//     Objeto *obj2 = new Objeto(pos_x -(areaVisao/2) + width/2 + (velocidade * cos((angulo - 60) * PI/180)) * width * distVisao, 
//                               pos_y -(areaVisao/2) + height/2 + (velocidade * sin((angulo - 60) * PI/180)) * height * distVisao, 
//                               areaVisao, 
//                               areaVisao);

//     Objeto *obj3 = new Objeto(pos_x -(areaVisao/2) + width/2 + (velocidade * cos((angulo + 60) * PI/180)) * width * distVisao, 
//                               pos_y -(areaVisao/2) + height/2 + (velocidade * sin((angulo + 60) * PI/180)) * height * distVisao, 
//                               areaVisao, 
//                               areaVisao);

//     if (obj1->verf_colisao(comida))
//         aceleracao_angular = 0;
    
//     if (obj2->verf_colisao(comida)) {
//         angulo = (angulo - atracaoFeromonio) % 360;
//         aceleracao_angular = 0;
//     }

//     if (obj3->verf_colisao(comida)) {
//         angulo = (angulo + atracaoFeromonio) % 360;
//         aceleracao_angular = 0;
//     }

//     // r->changeColor(100, 255, 100, 255);
//     // obj1->draw(r);
//     // obj2->draw(r);
//     // obj3->draw(r);

// }

int Formiga::get_dir_y() {

    return (dir_y*distVisao + pos_y + width/2);

}

int Formiga::get_dir_x() {
    
    return (dir_x*distVisao + pos_x + height/2);

}