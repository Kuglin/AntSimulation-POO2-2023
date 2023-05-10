#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

#include "Objeto.h"
#include "Feromonio.h"
#include "Renderer.h"

class Grid {
    private:

        Objeto*** grid;
        
        vector<Objeto*> objetos;
        //list<Feromonios> feromonios;

        int linhas;
        int colunas;

    public:

        Grid(int linhas, int colunas);

        void inserir(Objeto* obj);

        bool verf_colisao(int x, int y);

        void exibir(Renderer *r);
};

#endif