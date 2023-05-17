#ifndef FEROMONIO_H
#define FEROMONIO_H

#include "Objeto.h"
#include "Renderer.h"

class Feromonio : public Ponto {

    private:

        int duracao;
        
    public:

        // Construtor
        Feromonio(int x, int y, int duracao, bool comida); 
        
        // Retorna 1 se acabou sua duração
        bool diminuirDuracao();

        bool achouComida;

};      

#endif