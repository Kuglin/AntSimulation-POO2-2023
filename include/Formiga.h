#ifndef FORMIGA_H
#define FORMIGA_H

#include "Objeto.h"
#include "Renderer.h"

class Grid;

class Formiga : public Objeto {

    private:

        // Vetor que indica Direção da Formiga
        float dir_x;
        float dir_y;

        // Posição Relativa
        float pos_xR;
        float pos_yR;

        // Campo de visão
        int distVisao = 60;

        // Modulo do Vetor anterior, indica quantos pixels a formiga se move
        float velocidade;

        // Angulo do Vetor de direção da formiga
        int angulo;

        // Mudança que ocorre no angulo
        int aceleracao_angular;

        // Intervalo entre soltar feromonio
        int tempoFer = 10;

    public:

        // Construtor
        Formiga(int x, int y, int w, int h,float vel, int angulo_inicial);

        // Girar o vetor de direção em um angulo aleatorio
        void girar_vetor(int ang);

        // Gira Formiga em uma direção aleatoria
        void girar_aleatorio();

        // Move formiga, conforme a direção indicada pelo vetor
        void mover_dir();

        // Funcões para mover o Formiga
        void move_x(float v);
        void move_y(float v);

        // Verifica se houve colisão com outro objeto
        void visao(Grid* grid, Renderer *r);

        // Desenha formiga na tela
        void draw(Renderer *r);

        // Retorna 1 se for momento de soltar feromonio ou 0 se não
        bool soltarFeromonio();

        // 0 se está carregando comida ou 1 se está com comida
        bool hasFood = 0;
        
};

#endif