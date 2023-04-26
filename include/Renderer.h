#ifndef RENDERER_H
#define RENDERER_H

#include <SDL2/SDL.h>


class Renderer
{
public:

    Renderer(SDL_Window *sdlWindow);

    SDL_Renderer *get_sdlRenderer() const;

    void drawPoint(int x, int y);
    
    void drawLine(int x1, int y1, int x2, int y2);

    void changeColor(int r, int g, int b, int a);

    void update();

    void clear();

    void mudarCor(int i);

private:
    SDL_Renderer *sdlRenderer = nullptr;

    int r, g, b, a;
};

#endif