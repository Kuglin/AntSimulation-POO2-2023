#include "Feromonio.h"
#include <iostream>
#include "Grid.h"

#define DURACAO_FEROMONIO 500

Feromonio::Feromonio(int x, int y, bool achouComida, Renderer* r, Grid* grid) : Ponto(x, y){

    if (achouComida) {
        this->type = Type::feromonioComida;
        
        durFerCom = DURACAO_FEROMONIO;
        qtdFerCom = 1;

        durFerCas = 0;
        qtdFerCas = 0;
    }
        
    else {
        this->type = Type::feromonioCasa;

        durFerCom = 0;
        qtdFerCom = 0;

        durFerCas = DURACAO_FEROMONIO;
        qtdFerCas = 1;

    }
        
    this->achouComida = achouComida;

    this->r = r;

    this->grid = grid;
}

bool Feromonio::diminuirDuracao() {

    if (achouComida)
        r->changeColor(255, 100, 100, 255);

    else
        r->changeColor(100, 100, 255, 255);

    if ((qtdFerCas + qtdFerCom) > 1)
        r->drawPoint(pos_x, pos_y);

    if (durFerCas >= 0)
        durFerCas -= qtdFerCas;

    if (durFerCas <= (qtdFerCas*DURACAO_FEROMONIO)-DURACAO_FEROMONIO)
        qtdFerCas -= 1;

    if (durFerCom >= 0)
        durFerCom -= qtdFerCom;

    if (durFerCom <= (qtdFerCom*DURACAO_FEROMONIO)-DURACAO_FEROMONIO)
        qtdFerCom -= 1;

    if (durFerCas <= 1 && durFerCom <= 1)
        return 0;

    return 1;
}

int Feromonio::getQtdFer(bool achouComida) {

//Caso a formiga tiver comida, segue os ferômonios de casa
    if (achouComida) 
        return qtdFerCas;

    return qtdFerCom;
}

//Insere mais ferômonios, varia o tipo inserido dependendo se a formiga tiver comida ou não
void Feromonio::inserirFer(bool achouComida) {

    if (achouComida) {
        qtdFerCom += 1;
        durFerCom += DURACAO_FEROMONIO;

        if (qtdFerCom > qtdFerCas)
            type = Type::feromonioComida;

    }

    else {
        qtdFerCas += 1;
        durFerCas += DURACAO_FEROMONIO;

        if (qtdFerCas > qtdFerCom)
            type = Type::feromonioCasa;

    }

}