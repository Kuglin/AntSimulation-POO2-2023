#ifndef OBJETO_H
#define OBJETO_H

#include <SDL2/SDL.h>

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

        // Retorna o Retangulo do SDL
        const SDL_Rect* get_rect();
};


#endif