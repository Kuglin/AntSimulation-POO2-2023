#ifndef FEROMONIO_H
#define FEROMONIO_H

#include "Objeto.h"
#include "Renderer.h"

class Feromonio : public Ponto {

    private:

        int duracao;
        

    public:

        Feromonio(int x, int y, int duracao, bool comida);

        bool diminuirDuracao();

        bool achouComida;

};      

#endif