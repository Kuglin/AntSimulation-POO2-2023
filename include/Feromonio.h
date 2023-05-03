#ifndef FEROMONIO_H
#define FEROMONIO_H

#include "Objeto.h"
#include "Renderer.h"

class Feromonio : public Objeto {
    private:
        int duracao;
    public:
        Feromonio(int x, int y, int w, int h, int duracao);
};

#endif