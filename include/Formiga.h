#ifndef FORMIGA_H
#define FORMIGA_H

#include "Objeto.h"
#include "Renderer.h"

class Formiga : public Objeto {

    private:

        // Vetor que indica Direção da Formiga
        float dir_x;
        float dir_y;

        // Modulo do Vetor anterior, indica quantos pixels a formiga se move
        float velocidade;

        // Angulo do Vetor de direção da formiga
        float angulo;

        // Mudança que ocorre no angulo a cada tick
        int aceleracao_angular;

    public:

        // Construtor
        Formiga(int x, int y, int w, int h,float vel);

        // Girar o vetor de direção em um angulo aleatorio
        void girar_vetor();

        // Move formiga, conforme a direção indicada pelo vetor
        void mover();

        // Desenha formiga na tela
        void draw(Renderer *r);

};

#endif