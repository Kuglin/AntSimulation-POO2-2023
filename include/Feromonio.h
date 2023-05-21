#ifndef FEROMONIO_H
#define FEROMONIO_H

#include "Objeto.h"
#include "Renderer.h"

#define DURACAO_FEROMONIO 2000

class Feromonio : public Ponto {

    private:

        int qtdFerCom;
        int durFerCom;

        int qtdFerCas;
        int durFerCas;
        
    public:

        // Construtor
        Feromonio(int x, int y, bool comida); 
        
        // Retorna 1 se acabou sua duração
        bool diminuirDuracao();

        bool achouComida;

        int getQtdFer(bool achouComida);

        void inserirFer(bool achouComida);

};      

#endif