#include "FuncoesAuxiliares.h"

int gerar_random(int ini, int fim) {

    int tam = fim - ini + 1;

    int random = ((rand() % tam) + ini);

    return random;

}