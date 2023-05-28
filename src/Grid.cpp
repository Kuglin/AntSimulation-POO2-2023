#include "Grid.h"
#include "FuncoesAuxiliares.h"

#include <iostream>
using namespace std;

bool feromonioRemove (Feromonio *f) {

    if(!f->update()) {
        f->grid->grid[f->get_pos_x()][f->get_pos_y()] = nullptr;
        return 1;
    };
    
    return 0;
}

Grid::Grid(int linhas, int colunas, int qtd_formigas) {

    this->linhas = linhas;
    this->colunas = colunas;

    //Preenche a matriz com Pontos
    grid = new Ponto**[linhas];

    for (int i = 0; i < (linhas); i++) {
        grid[i] = new Ponto*[colunas];
        for (int j = 0; j < (colunas); j++)
            grid[i][j] = nullptr;
    }

    //Gera a quantidade de formigas especificada no construtor, com uma direção aleatória
    for (int i = 0; i < qtd_formigas; i++)
        formigas.push_back(new Formiga(300, 400, 10, 10, 1, gerar_random(0,360)));
    
}

void Grid::inserir(Objeto* obj) {

    objetos.push_back(obj);

    //Pega a posição do objeto
    int pos_x = obj->get_pos_x();
    int pos_y = obj->get_pos_y();

    int pos_x2 = pos_x + obj->get_width();
    int pos_y2 = pos_y + obj->get_height();

    //Insere na matriz "grid" um Objeto (que herda Ponto), para sinalizar todas as posições que ele ocupa
    for (int i = pos_x; i < pos_x2; i++)
        for (int j = pos_y; j < pos_y2; j++)  
            grid[i][j] = obj;
        
}

void Grid::inserir(Feromonio* feromonio) {
    //Pega a posição do ferômonio e insere na matriz
    int pos_x = feromonio->get_pos_x();
    int pos_y = feromonio->get_pos_y();

    this->feromonios.push_front(feromonio);

    grid[pos_x][pos_y] = feromonio;

}

void Grid::inserir(Formigueiro* formigueiro) {

    formigueiro->type = Type::formigueiro;

    this->formigueiro = formigueiro;

    //Pega a posição do objeto
    int pos_x = formigueiro->get_pos_x();
    int pos_y = formigueiro->get_pos_y();

    int pos_x2 = pos_x + formigueiro->get_width();
    int pos_y2 = pos_y + formigueiro->get_height();

    //Insere na matriz "grid" um Objeto (que herda Ponto), para sinalizar todas as posições que ele ocupa
    for (int i = pos_x; i < pos_x2; i++)
        for (int j = pos_y; j < pos_y2; j++)  
            grid[i][j] = formigueiro;

}

void Grid::inserirCom(Objeto* obj) {

    obj->type = Type::comida;
    comidas.push_back(obj);

    //Pega a posição do objeto
    int pos_x = obj->get_pos_x();
    int pos_y = obj->get_pos_y();

    int pos_x2 = pos_x + obj->get_width();
    int pos_y2 = pos_y + obj->get_height();

    //Insere na matriz "grid" um Objeto (que herda Ponto), para sinalizar todas as posições que ele ocupa
    for (int i = pos_x; i < pos_x2; i++)
        for (int j = pos_y; j < pos_y2; j++)  
            grid[i][j] = obj;

}

void Grid::inserirFer(int pos_x, int pos_y, bool achouComida, Renderer *r) {

    if (grid[pos_x][pos_y] == nullptr)
        inserir(new Feromonio(pos_x, pos_y, achouComida, r, this));

    else if (grid[pos_x][pos_y]->type == Type::feromonioComida || grid[pos_x][pos_y]->type == Type::feromonioCasa)
        static_cast<Feromonio*>(grid[pos_x][pos_y])->inserirFer(achouComida);

}


void Grid::exibir(Renderer *r) {

    r->changeColor(255, 255, 255, 255);

    // Exibir Objetos

    for (int i = 0; i < objetos.size(); i++)
        r->drawRect(objetos[i]->get_rect());

    // Exibir Formigas

    for (int i = 0; i < formigas.size(); i++) {
            
        if (formigas[i]->soltarFeromonio()) {

            int pos_x = formigas[i]->get_pos_x() + formigas[i]->get_width()/2;
            int pos_y = formigas[i]->get_pos_y() + formigas[i]->get_height()/2;
        
            inserirFer(pos_x, pos_y, formigas[i]->hasFood, r);

        }
        
        formigas[i]->visao(this, r);
        formigas[i]->mover_dir(this);

        formigas[i]->draw(r);

    }

    // Exibir Feromonios
    feromonios.remove_if(feromonioRemove);

    // Exibir Formigueiro
    r->drawRect(formigueiro->get_rect());

    // Exibir Comida
    r->changeColor(100, 255, 100, 255);

    for (int i=0; i < comidas.size(); i++)
        r->drawRect(comidas[i]->get_rect());

}

int Grid::get_GridPosType(int pos_x, int pos_y) {
    
    if ( (pos_x >= 0) && (pos_x < linhas) && (pos_y >= 0) && (pos_y < colunas)) {
        if (grid[pos_x][pos_y])
            return grid[pos_x][pos_y]->type;

        return -2;
    }
    
    return -1;

}

int Grid::getQtdFer(int pos_x, int pos_y, bool AchouComida) {

    if (grid[pos_x][pos_y]->type == Type::feromonioComida) {
        return static_cast<Feromonio*>(grid[pos_x][pos_y])->getQtdFer(AchouComida);
    }

    return 0;

}

bool Grid::existPos(int pos_x, int pos_y) {

    if ( (pos_x >= 0) && (pos_x < linhas) && (pos_y >= 0) && (pos_y < colunas))
        return 1;

    return 0;

}