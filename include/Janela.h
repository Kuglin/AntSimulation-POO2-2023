#ifndef JANELA_H
#define JANELA_H

#include "Sdl.h"
#include "Renderer.h"

#include <SDL2/SDL.h>

class Janela
{

public:

    Janela(char *title, int w, int h);

    ~Janela();

    SDL_Window *get_sdlWindow();

    int get_width();

    int get_height();

    void loop();

private:
    SDL_Window *sdlWindow = nullptr;

    // Largura e Altura
    int width;
    int height;

    // Titulo
    char *title;

    Sdl *sdl;

    Renderer *renderer;
    
};

#endif