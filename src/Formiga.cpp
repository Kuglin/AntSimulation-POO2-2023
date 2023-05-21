#include "Formiga.h"
#include "FuncoesAuxiliares.h"
#include "Grid.h"

#include <cmath>
#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

Formiga::Formiga(int x, int y, int w, int h, float vel, int angulo_inicial) : Objeto(x, y, w, h){

    this->velocidade = vel;

    this->dir_x = 0;
    this->dir_y = 0;

    this->pos_xR = x;
    this->pos_yR = y;

    this->angulo = angulo_inicial;
    this->aceleracao_angular = (gerar_random(-1, 1));

    this->type = Type::formiga;

}

void Formiga::girar_vetor(int angulo) {

    this->angulo = int(this->angulo + angulo) % 360;

    dir_x = velocidade * cos(conv_radianos(this->angulo));
    dir_y = velocidade * sin(conv_radianos(this->angulo));
}

void Formiga::girar_aleatorio() {

    // Se o número aleatório for 0, a direção da formiga muda;
    if ((gerar_random(0,50)) == 0)
        aceleracao_angular = gerar_random(-1,1);

    girar_vetor(aceleracao_angular);

}

void Formiga::mover_dir(Grid* grid) {

    int pos_type = grid->get_GridPosType(dir_x+pos_x+height/2, dir_y+pos_y+width/2);

    if ( pos_type == 1 || pos_type == -1)
        girar_vetor(180);

    else if (pos_type == 4) {
        girar_vetor(180);
        hasFood = 1;
    }

    move_x(dir_x);
    move_y(dir_y);  

}

void Formiga::move_x(float v) {

    //Para quando a formiga anda com alguma angulação, pos_xR é a quantidade de movimento real do eixo x;
    pos_xR += v;
    pos_x = pos_xR;
    //O rect é o objeto do SDL que representa a formiga. É alterado x para alterar na tela;
    rect.x = pos_x;

}

void Formiga::move_y(float v) {
    
    //Para quando a formiga anda com alguma angulação, pos_yR é a quantidade de movimento real do eixo y;
    pos_yR += v;
    pos_y = pos_yR;
    //O rect é o objeto do SDL que representa a formiga. É alterado y para alterar na tela;
    rect.y = pos_y;

}

void Formiga::draw(Renderer *r){
    
    r->drawRect(&rect);
    r->drawLine(pos_x + width/2, pos_y + height/2, pos_x + width/2 + dir_x * width , pos_y + height/2 + dir_y * height);

}

bool Formiga::soltarFeromonio() {

    //Executa toda vez que a formiga anda, quando tempoFer chegar a 0, solta o ferômonio,
    //e restabelece o tempoFer para 10. Retorna 1 se soltar o ferômonio, 0 se não
    tempoFer -= 1;

    if (tempoFer == 0) {
        
        tempoFer = 10;
        return 1;

    }

    return 0;
}

void Formiga::visao(Grid* grid, Renderer *r) {

    int vis_x;
    int vis_y; 

    r->changeColor(255,255,100,255);

    int qtdFer = 0;
    int qtdMaxFer = 0;
    int angMax = -angVisao/2 + angVisao/3;

    for (int ini = -angVisao/2; ini < angVisao/2; ini+= angVisao/3) {
        for (int ang = ini; ang < ini+angVisao/3; ang++) {
            
            vis_x = (distVisao * cos(conv_radianos(ang + this->angulo))) + pos_x + width/2;
            vis_y = (distVisao * sin(conv_radianos(ang + this->angulo))) + pos_y + height/2;

            r->drawPoint(vis_x, vis_y);

            int pos_type = grid->get_GridPosType(vis_x, vis_y);
            cout << pos_type << "\n";

            if (pos_type == (hasFood + 5)) {
                qtdFer += 1;
            }

            else if (pos_type == 4 && !hasFood) {
                qtdFer += 10;
                
            }
        }

        if (qtdFer > qtdMaxFer) {

            qtdMaxFer = qtdFer;
            angMax = ini;

        }

        qtdFer = 0;
            
    }

    angulo += angMax + angVisao/6;

}
