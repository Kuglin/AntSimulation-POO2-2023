#ifndef PONTO_H
#define PONTO_H

#include "Tipo.h"

class Ponto {

    protected:

        int pos_x;
        int pos_y;

    public:

        //Construtor
        Ponto(int x, int y);

        //Tipo do Ponto
        Type type = Type::ponto;

        //Getters
        int get_pos_x();
        int get_pos_y();
};

#endif
