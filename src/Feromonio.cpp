#include "Feromonio.h"
#include <iostream>

Feromonio::Feromonio(int x, int y, bool achouComida) : Ponto(x, y){

    if (achouComida) {
        this->type = Type::feromonioComida;
        
        durFerCom = DURACAO_FEROMONIO;
        qtdFerCom = 1;

        durFerCas = 0;
        qtdFerCas = 0;
    }
        
    else {
        this->type = Type::feromonioCasa;

        durFerCom = DURACAO_FEROMONIO;
        qtdFerCom = 1;

        durFerCas = 0;
        qtdFerCas = 0;

    }
        
    this->achouComida = achouComida;
}

bool Feromonio::diminuirDuracao() {

    if (durFerCas > 0)
        durFerCas -= 1;

    if (durFerCas <= (qtdFerCas*DURACAO_FEROMONIO)-DURACAO_FEROMONIO)
        qtdFerCas -= 1;

    if (durFerCom > 0)
        durFerCom -= 1;

    if (durFerCom <= (qtdFerCom*DURACAO_FEROMONIO)-DURACAO_FEROMONIO)
        qtdFerCom -= 1;

    if (durFerCas < 1 && durFerCom < 1)
        return 0;

    return 1;
}

int Feromonio::getQtdFer(bool achouComida) {

    if (!achouComida) 
        return qtdFerCom;

    return qtdFerCas;
}

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