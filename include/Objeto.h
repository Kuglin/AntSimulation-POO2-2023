#ifndef OBJETO_H
#define OBJETO_H

#include <SDL2/SDL.h>
#include "Renderer.h"

class Objeto {


    protected:

        // Posição do Objeto
        float pos_x;
        float pos_y;
        
        // Largura e Altura do Objeto
        int width;
        int height;

        // Retangulo do SDL, usado para exibir o Objeto na Tela
        SDL_Rect rect;

    public:

        // Construtor
        Objeto(int x, int y, int w, int h);
        
        // Funcões para mover o Objeto
        void move_x(float v);
        void move_y(float v);
        
        // Desenha o Objeto na Tela
        void draw(Renderer *r);

        // Retorna o Retangulo do SDL
        const SDL_Rect* get_rect();

        //Getters
        float get_pos_x();
        float get_pos_y();

        int get_width();
        int get_height();
};


#endif