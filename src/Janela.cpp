#include "Janela.h"
#include "FuncoesAuxiliares.h"
#include "Formiga.h"

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#define PI 3.14159265

// Construtor
Janela::Janela(const char *titulo, int w, int h)
{
    sdl = Sdl::criar();

    title = title;
    width = w;
    height = h;

    sdlWindow = SDL_CreateWindow(titulo, 0, 0, w, h, SDL_WINDOW_SHOWN);
    renderer = new Renderer(sdlWindow);
}

// Destrutor
Janela::~Janela()
{

    SDL_DestroyWindow(sdlWindow);
}

// Retornar janela sdl
SDL_Window *Janela::get_sdlWindow()
{
    return sdlWindow;
}

int Janela::get_height()
{
    return height;
}

int Janela::get_width()
{
    return width;
}

void Janela::loop()
{   

    bool running = 1;

    Formiga *f1 = new Formiga(300, 300, 50, 50, 1);
    Formiga *f2 = new Formiga(300, 400, 50, 50, 1);

    while (running)
    {   
        
        renderer->clear();

        switch (sdl->handleEvents())
        {
        case 0:
            running = 0;
            break;
        }

        renderer->changeColor(255, 255, 255, 255);

        f1->girar_vetor();
        f1->mover();
        f1->draw(renderer);

        f2->girar_vetor();
        f2->mover();
        f2->draw(renderer);

        SDL_Delay(10);
        renderer->update();

    }

}