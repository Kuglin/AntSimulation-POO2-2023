#ifndef FUNCOESAUXILIARES_H
#define FUNCOESAUXILIARES_H

#include <cstdlib>
#include <time.h>

float gerar_random() {

    srand(time(NULL));

    return (rand() % 3)-1;
}




#endif