#include "Grid.h"

#include <iostream>
using namespace std;

Grid::Grid(int linhas, int colunas) {

    this->linhas = linhas;
    this->colunas = colunas;

    grid = new Objeto**[linhas];

    for (int i = 0; i < (linhas); i++) {
        grid[i] = new Objeto*[colunas];
        for (int j = 0; j < (colunas); j++)
            grid[i][j] == nullptr;
    }
}

void Grid::inserir(Objeto* obj) {

    objetos.push_back(obj);

    for (int i = obj->get_pos_x(); i < obj->get_pos_x() + obj->get_width(); i++)
        for (int j = obj->get_pos_y(); j < obj->get_pos_y() + obj->get_height(); j++)  
            grid[i][j] = obj;
            
}

bool Grid::verf_colisao(int x, int y) {

    if (x >= linhas || y >= colunas || x < 0 || y < 0)
        return 0;

    if (grid[x][y] != nullptr)
        return 1;

    return 0;

}

void Grid::exibir(Renderer *r) {

    for (int i = 0; i < objetos.size(); i++)
        r->drawRect(objetos[i]->get_rect());

}