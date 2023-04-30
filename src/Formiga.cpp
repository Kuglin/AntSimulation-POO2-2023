#include "Formiga.h"
#include "FuncoesAuxiliares.h"

#include <cmath>
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#define PI 3.14159265

Formiga::Formiga(int x, int y, int w, int h, float vel) : Objeto(x, y, w, h){

    velocidade = vel;

    dir_x = 0;
    dir_y = 0;

    angulo = 0;
    aceleracao_angular = ((rand() % 3)-1);

}

void Formiga::girar_vetor() {

    if ((gerar_random(0,100)) == 0)
        aceleracao_angular = gerar_random(-1,1);

    angulo += aceleracao_angular;

    dir_x = velocidade * cos(angulo * PI/180);
    dir_y = velocidade * sin(angulo * PI/180);
}

void Formiga::mover() {

    move_x(dir_x);
    move_y(dir_y);
    
}

void Formiga::draw(Renderer *r) {

    r->drawRect(&rect);
    r->drawLine(pos_x + width/2, pos_y + height/2, pos_x + width/2 + dir_x * width, pos_y + height/2 + dir_y * height);

}