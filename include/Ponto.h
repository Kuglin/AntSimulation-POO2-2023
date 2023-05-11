#ifndef PONTO_H
#define PONTO_H

class Ponto {

    protected:

        int pos_x;
        int pos_y;

    public:

        Ponto(int x, int y);
        int type = 0;

        //Getters
        int get_pos_x();
        int get_pos_y();
};

#endif
