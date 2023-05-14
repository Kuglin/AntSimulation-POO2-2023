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

    pos_xR = x;
    pos_yR = y;

    angulo = angulo_inicial;
    aceleracao_angular = ((rand() % 3)-1);

}

void Formiga::girar_vetor(int ang) {

    angulo = int(angulo + ang) % 360;

    dir_x = velocidade * cos(angulo * PI/180);
    dir_y = velocidade * sin(angulo * PI/180);
}

void Formiga::girar_aleatorio() {

    if ((gerar_random(0,50)) == 0)
        aceleracao_angular = gerar_random(-1,1);

    girar_vetor(aceleracao_angular);

}

void Formiga::mover_dir() {

    move_x(dir_x);
    move_y(dir_y);
    
}

void Formiga::move_x(float v) {

    pos_xR += v;
    pos_x = pos_xR;
    rect.x = pos_x;

}

void Formiga::move_y(float v) {

    pos_yR += v;
    pos_y = pos_yR;
    rect.y = pos_y;

}

void Formiga::draw(Renderer *r){
    
    r->drawRect(&rect);
    r->drawLine(pos_x + width/2, 
    pos_y + height/2, 
    pos_x + width/2 + dir_x * width ,
    pos_y + height/2 + dir_y * height);

}

int Formiga::get_dir_y() {

    return (dir_y*5 + pos_yR + width/2);

}

int Formiga::get_dir_x() {
    
    return (dir_x*5 + pos_xR + height/2);

}

bool Formiga::soltarFeromonio() {

    tempoFer -= 1;

    if (tempoFer == 0) {
        
        tempoFer = 10;
        return 1;

    }

    return 0;
}

void Formiga::visao(Ponto*** grid, Renderer *r) {

    int vis_x;
    int vis_y; 

    bool achou = 0;
    
    r->changeColor(255,255,100,255);


    for (int ang = -30; ang < 30; ang++) {

        for (int i = 1; i < distVisao; i++) {
            

            vis_x = (i * cos((ang + angulo) * PI/180)) + pos_x + width/2;
            vis_y = (i * sin((ang + angulo) * PI/180)) + pos_y + height/2;

            r->drawPoint(vis_x, vis_y);

            //cout << vis_y << "\n";

            if ( (vis_x > 0) && (vis_x <= 800) && (vis_y > 0) && (vis_y <= 600) && !achou) { 
                if (grid[vis_x][vis_y]){
                        if ( grid[vis_x][vis_y]->type == 2) {
                    
                            angulo += ang;
                            aceleracao_angular = 0;
                            achou = 1;

                    }
                }
            }

        }

    }




}