#pragma once

#ifndef GRID_H
#define GRID_H

#include <vector>
using namespace std;

#include "Objeto.h"
#include "Feromonio.h"
#include "Renderer.h"
#include "Formiga.h"
#include "Formigueiro.h"

class Grid {
    private:

        //É um ponteiro que aponta para um array de ponteiros que apontam para arrays de ponteiros de Pontos
        //Ou seja, um ponteiro para uma matriz de Pontos
        
        
        //Listas dos itens do Grid
        vector<Objeto*> objetos;

        vector<Feromonio*> feromonios;

        vector<Formiga*> formigas;

        vector<Objeto*> comidas;

        int linhas;
        int colunas;

        

    public:

    Ponto*** grid;

        Grid(int linhas, int colunas, int qtd_formigas);

        void inserir(Objeto* obj);
        void inserir(Feromonio* feromonio);

        void inserirFer(int pos_x, int pos_y, bool achouComida);

        void exibir(Renderer *r);

        //Pega o tipo de um ponto do Grid, o tipo é classificado pelo enum Tipo
        int get_GridPosType(int pos_x, int pos_y); 

        Formigueiro* formigueiro;

        int getQtdFer(int pos_x, int pos_, bool achouComida);

        bool existPos(int pos_x, int pos_y);

};

#endif