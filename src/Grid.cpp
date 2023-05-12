#include "Grid.h"
#include "FuncoesAuxiliares.h"

#include <iostream>
using namespace std;

Grid::Grid(int linhas, int colunas, int qtd_formigas) {

    this->linhas = linhas;
    this->colunas = colunas;

    grid = new Ponto**[linhas];

    for (int i = 0; i < (linhas); i++) {
        grid[i] = new Ponto*[colunas];
        for (int j = 0; j < (colunas); j++)
            grid[i][j] = nullptr;
    }

    for (int i = 0; i < qtd_formigas; i++)
        formigas.push_back(new Formiga(300, 400, 10, 10, 1, gerar_random(0,360)));

    inserir(new Objeto(740, 540, 30, 30));
    grid[740][540]->type = 4;
    
}

void Grid::inserir(Objeto* obj) {

    objetos.push_back(obj);

    int pos_x = obj->get_pos_x();
    int pos_y = obj->get_pos_y();

    int pos_x2 = pos_x + obj->get_width();
    int pos_y2 = pos_y + obj->get_height();

    for (int i = pos_x; i < pos_x2; i++)
        for (int j = pos_y; j < pos_y2; j++)  
            grid[i][j] = obj;
        
}

void Grid::inserir(Feromonio* feromonio) {

    int pos_x = feromonio->get_pos_x();
    int pos_y = feromonio->get_pos_y();

    feromonios.push_back(feromonio);
    
    grid[pos_x][pos_y] = feromonio;

}

int Grid::verf_colisao(int x, int y) {

    if ((x >= linhas) || (y >= colunas) || (x < 0) || (y < 0))
        return 1;

    if (grid[x][y])
        return grid[x][y]->type;

    return 0;

}

void Grid::exibir(Renderer *r) {

    r->changeColor(255, 255, 255, 255);

    // Exibir Objetos

    for (int i = 0; i < objetos.size(); i++)
        r->drawRect(objetos[i]->get_rect());

    // Exibir Formigas

    for (int i = 0; i < formigas.size(); i++) {

        int dir_x = formigas[i]->get_dir_x();
        int dir_y = formigas[i]->get_dir_y();
            
        formigas[i]->girar_aleatorio();

        int obj_colisao = verf_colisao(dir_x, dir_y);

        if (obj_colisao == 1)
            formigas[i]->girar_vetor(90);

        if (obj_colisao == 4) {
            formigas[i]->girar_vetor(90);
            formigas[i]->hasFood = 1;

        }

            
        if (formigas[i]->soltarFeromonio()) {

            int pos_x = formigas[i]->get_pos_x() + formigas[i]->get_width()/2;
            int pos_y = formigas[i]->get_pos_y() + formigas[i]->get_height()/2;
        
            inserir(new Feromonio(pos_x, pos_y, 500, formigas[i]->hasFood));

        }

        formigas[i]->mover_dir();

        r->changeColor(255, 255, 255, 255);
        formigas[i]->draw(r);

    }

    // Exibir Feromonios

    r->changeColor(100, 100, 255, 255);

    for (int i = 0; i < feromonios.size(); i++) {
        
        int pos_x = feromonios[i]->get_pos_x();
        int pos_y = feromonios[i]->get_pos_y();

        if (feromonios[i]->achouComida)
            r->changeColor(255, 100, 100, 255);
            

        else
            r->changeColor(100, 100, 255, 255);
            

        r->drawPoint(pos_x, pos_y);
        
        if (!feromonios[i]->diminuirDuracao()) {
            
            grid[pos_x][pos_y] = nullptr;
            delete feromonios[i];
            feromonios.erase(feromonios.begin()+i);
            
        }

    }

    r->changeColor(100, 255, 100, 255);

    for (int i=0; i < comidas.size(); i++)
        r->drawRect(comidas[i]->get_rect());



}