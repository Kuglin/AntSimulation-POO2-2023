#include "Feromonio.h"

Feromonio::Feromonio(int x, int y, int duracao) : Ponto(x, y){

    this->duracao = duracao;
    type = 2;

}

bool Feromonio::diminuirDuracao() {

    duracao -= 1;

    if (duracao < 1)
        return 0;
    
    return 1;

}