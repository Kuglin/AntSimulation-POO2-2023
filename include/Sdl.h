#ifndef SDL_H
#define SDL_H

#include <SDL2/SDL.h>

class Sdl
{
    public:    

        ~Sdl();

        const Uint8* currentKeyStates = SDL_GetKeyboardState( NULL );

        static Sdl *criar();

        int handleEvents();
    

    private:
        Sdl();

        static Sdl* sdl;

        SDL_Event eventHandler;
};

#endif