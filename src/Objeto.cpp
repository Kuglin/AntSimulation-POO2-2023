#include "Objeto.h"

#include <iostream>
using namespace std;

Objeto::Objeto(int x, int y, int w, int h) {

    pos_x = x;
    pos_y = y;
    width = w;
    height = h;

    rect.x = 300;
    rect.y = 300;
    rect.w = 50;
    rect.h = 50;

}

void Objeto::move_x(float v) {

    pos_x += v;
    rect.x = pos_x;

}

void Objeto::move_y(float v) {

    pos_y += v;
    rect.y = pos_y;

}

const SDL_Rect* Objeto::get_rect() {

    return &rect;

}
