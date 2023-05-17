#include "Feromonio.h"

Feromonio::Feromonio(int x, int y, int duracao, bool achouComida) : Ponto(x, y){

    this->duracao = duracao;

    if (achouComida)
        this->type = Type::feromonioComida;
    else
        this->type = Type::feromonioCasa;

    this->achouComida = achouComida;

}

bool Feromonio::diminuirDuracao() {

    duracao -= 1;

    if (duracao < 1)
        return 0;
    
    return 1;

}