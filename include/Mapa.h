#ifndef MAPA_H
#define MAPA_H

#include "Objeto.h"

class Mapa {
    private:
        Objeto** grid;
        int tam;
        int colunas;

    public:
        Mapa(int tam, int colunas);
        void inserir(Objeto* obj);
};

#endif