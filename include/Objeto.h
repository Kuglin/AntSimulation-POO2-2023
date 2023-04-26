#ifndef OBJETO_H
#define OBJETO_H

#include <SDL2/SDL.h>

// Não esta sendo utilizado

class Objeto {


    private:

        float pos_x;
        float pos_y;

        int width;
        int height;

        SDL_Rect rect;

    public:

        Objeto(int x, int y, int w, int h);
        
        void set_x(int new_x);
        void set_y(int new_y);
};


#endif