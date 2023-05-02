#include "Janela.h"
#include "FuncoesAuxiliares.h"
#include "Formiga.h"

#include <SDL2/SDL.h>

#include <iostream>
using namespace std;

#define PI 3.14159265
#define QTD_FORMIGAS 100

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

    int qtd_objetos = 7;
    Objeto *objetos [qtd_objetos];
    for (int i=0; i<6; i++) objetos[i] = nullptr;

    objetos[0] = new Objeto(0, 0, width, 1);
    objetos[1] = new Objeto(0, 0, 1, height);
    objetos[2] = new Objeto(width-1, 0, 1, height);
    objetos[3] = new Objeto(0, height-1, width, 1);
    objetos[4] = new Objeto(100, 100, 200, 200);
    objetos[5] = new Objeto(400, 300, 300, 300);
    objetos[6] = new Objeto(600, 0, 150, 150);

    int qtd_feromonios = 3; 
    Objeto *feromonios [qtd_feromonios];

    feromonios [0] = new Objeto(320,340, 20, 20);
    feromonios [1] = new Objeto(280,380, 20, 20);
    feromonios [2] = new Objeto(240,420, 20, 20);


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

                for (int j=0; j<qtd_objetos; j++) {

                    if (objetos[j]) {

                        if (formigas[i]->verf_colisao(objetos[j]))
                            formigas[i]->girar_vetor(90);
                    }
                }

                for (int j = 0; j < qtd_feromonios; j++)
                    formigas[i]->visao(feromonios[j], renderer);

                formigas[i]->mover();
                renderer->changeColor(255, 255, 255, 255);
                formigas[i]->draw(renderer);

            }
        }

        for (int i = 0; i < qtd_objetos; i++) 
            if (objetos[i])
                objetos[i]->draw(renderer);


        renderer->changeColor(200, 255, 100, 255);
        for (int i = 0; i < qtd_feromonios; i++)
            feromonios[i]->draw(renderer);

        renderer->update();

        SDL_Delay(10);

    }

}