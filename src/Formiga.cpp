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

void Formiga::mover() {

    move_x(dir_x);
    move_y(dir_y);
    
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
    r->drawLine(pos_x + width/2, pos_y + height/2, pos_x + width/2 + dir_x * width, pos_y + height/2 + dir_y * height);

}