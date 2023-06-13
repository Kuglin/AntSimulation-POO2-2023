#include "FuncoesAuxiliares.h"

#include <stdio.h>
#include <vector>

#define PI 3.14159265

int gerar_random(int ini, int fim) {

    int tam = fim - ini + 1;

    int random = ((rand() % tam) + ini);

    return random;

}

float conv_radianos(int angulo) {

    return (angulo * PI/180);

}

void eliminarValor(std::vector<int>& vetor, int tam, int valor){
    int* vetorAux=new int[tam-1];
    int j=0;
    for (int i=0; i<tam;i++){
        if(vetor[i]!=valor){
            vetorAux[j]=vetor[i];
            j++;
        }
    }
    vetor=vetorAux;
}