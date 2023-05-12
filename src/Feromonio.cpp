#include "Feromonio.h"

Feromonio::Feromonio(int x, int y, int duracao, bool comida) : Ponto(x, y){

    this->duracao = duracao;
    type = 2;
    achouComida = comida;

}

bool Feromonio::diminuirDuracao() {

    duracao -= 1;

    if (duracao < 1)
        return 0;
    
    return 1;

}