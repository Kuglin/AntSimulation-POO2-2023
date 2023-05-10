#include "Janela.h"
#include "FuncoesAuxiliares.h"
#include "Formiga.h"
#include "Feromonio.h"
#include "Grid.h"

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;
#define PI 3.14159265
#define QTD_FORMIGAS 1000

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

    Formiga *formigas [QTD_FORMIGAS];
    for (int i=0; i<QTD_FORMIGAS; i++) formigas[i] = new Formiga(300, 400, 10, 10, 1, gerar_random(0,360));

    Grid *grid = new Grid(800, 600);

    grid->inserir(new Objeto(0, 0, width, 1));
    grid->inserir(new Objeto(0, 0, 1, height));
    grid->inserir(new Objeto(width-1, 0, 1, height));
    grid->inserir(new Objeto(0, height-1, width, 1));
    grid->inserir(new Objeto(100, 100, 200, 200));
    grid->inserir(new Objeto(400, 300, 300, 300));
    grid->inserir(new Objeto(600, 0, 150, 150));

    // int qtd_feromonios = 3; 
    // Feromonio *feromonios [qtd_feromonios];

    // feromonios [0] = new Feromonio(320,340, 20, 20, 10);
    // feromonios [1] = new Feromonio(280,380, 20, 20, 10);
    // feromonios [2] = new Feromonio(240,420, 20, 20, 10);

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

        for (int i=0; i<QTD_FORMIGAS; i++) {
            if (formigas[i]) {
                
                formigas[i]->girar_aleatorio();

                if (grid->verf_colisao(formigas[i]->get_dir_x(), formigas[i]->get_dir_y())) {

                    formigas[i]->girar_vetor(180);

                }
                    
                // for (int j=0; j<qtd_objetos; j++) {

                //     if (objetos[j]) {

                //         if (formigas[i]->verf_colisao(objetos[j]))
                //             formigas[i]->girar_vetor(180);
                //     }
                // }

                // for (int j = 0; j < qtd_feromonios; j++)
                //     formigas[i]->visao(feromonios[j], renderer);

                formigas[i]->mover_dir();
                renderer->changeColor(255, 255, 255, 255);
                formigas[i]->draw(renderer);

            }
        }

        grid->exibir(renderer);

        renderer->update();

        SDL_Delay(10);

    }

}