#include "Janela.h"
#include "FuncoesAuxiliares.h"
#include "Formiga.h"
#include "Feromonio.h"
#include "Grid.h"

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;
#define PI 3.14159265
#define QTD_FORMIGAS 500

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

    Grid *grid = new Grid(800, 600, QTD_FORMIGAS);

    grid->inserir(new Objeto(0, 0, width, 1));
    grid->inserir(new Objeto(0, 0, 1, height));
    grid->inserir(new Objeto(width-1, 0, 1, height));
    grid->inserir(new Objeto(0, height-1, width, 1));
    grid->inserir(new Objeto(100, 100, 200, 200));
    grid->inserir(new Objeto(400, 300, 300, 300));
    grid->inserir(new Objeto(650, 0, 150, 150));

    while (running)
    {   
        
        renderer->clear();

        switch (sdl->handleEvents())
        {
        case 0:
            running = 0;
            break;
        }

        grid->exibir(renderer);

        renderer->update();

        SDL_Delay(0);
    }

}