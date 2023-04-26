#include "Janela.h"
#include "FuncoesAuxiliares.h"

#include <SDL2/SDL.h>
#include <cmath>
#include <iostream>
using namespace std;

#define PI 3.14159265

// Construtor
Janela::Janela(char *titulo, int w, int h)
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

    SDL_Rect miga;

    miga.x = 300;
    miga.y = 300;
    miga.w = 50;
    miga.h = 50;

    float miga_x = miga.x;
    float miga_y = miga.y;

    int r = 1;
    double v_x = 1;
    double v_y = 0;

    double angulo = 0;

    v_x = r * cos(angulo * PI/180);
    v_y = r * sin(angulo * PI/180);


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


        SDL_RenderDrawRect(renderer->get_sdlRenderer(), &miga);
        renderer->drawLine(miga.x + miga.w/2, miga.y + miga.h/2, miga.x + miga.w/2 + v_x * miga.w, miga.y + miga.h/2 + v_y * miga.h);
        
        angulo += gerar_random();
        v_x = r * cos(angulo * PI/180);
        v_y = r * sin(angulo * PI/180);

        miga_x += v_x;
        miga_y += v_y;

        miga.x = miga_x;
        miga.y = miga_y;

        SDL_Delay(10);
        renderer->update();

    }

}