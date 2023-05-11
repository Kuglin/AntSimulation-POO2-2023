#ifndef FORMIGA_H
#define FORMIGA_H

#include "Objeto.h"
#include "Renderer.h"

class Formiga : public Objeto {

    private:

        // Vetor que indica Direção da Formiga
        float dir_x;
        float dir_y;

        // Pos Relativa
        float pos_xR;
        float pos_yR;

        int distVisao = 4;
        int areaVisao = 30;
        int atracaoFeromonio = 10;

        // Modulo do Vetor anterior, indica quantos pixels a formiga se move
        float velocidade;

        // Angulo do Vetor de direção da formiga
        int angulo;

        // Mudança que ocorre no angulo a cada tick
        int aceleracao_angular;

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
        bool verf_colisao(Objeto *obj);

        // Verifica se existe algum feromonio no campo do visao e rotaciona na sua direção
        // void visao(Objeto *comida, Renderer *r);

        // Desenha formiga na tela
        void draw(Renderer *r);

        bool soltarFeromonio();

        int get_dir_x();
        int get_dir_y();
        
};

#endif