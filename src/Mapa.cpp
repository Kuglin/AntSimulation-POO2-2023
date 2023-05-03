#include "Mapa.h"
#include "Objeto.h"

Mapa::Mapa(int tam, int colunas) {
    this->tam = tam;
    this->colunas = colunas;
    grid = new Objeto*[tam];
    for (int i = 0; i < tam; i++) {
        grid[i] == nullptr;
    }
}

void Mapa::inserir(Objeto* obj) {
    
}