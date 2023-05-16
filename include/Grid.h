#pragma once

#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

#include "Objeto.h"
#include "Feromonio.h"
#include "Renderer.h"
#include "Formiga.h"

class Grid {
    private:

        Ponto*** grid;
        
        vector<Objeto*> objetos;

        vector<Feromonio*> feromonios;

        vector<Formiga*> formigas;

        vector<Objeto*> comidas;

        int linhas;
        int colunas;

    public:

        Grid(int linhas, int colunas, int qtd_formigas);

        void inserir(Objeto* obj);
        void inserir(Feromonio* feromonio);

        int verf_colisao(int x, int y);

        void exibir(Renderer *r);

        int get_GridPosType(int pos_x, int pos_y); 

};

#endif