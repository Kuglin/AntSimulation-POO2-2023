#include "Objeto.h"

#include <iostream>
using namespace std;

Objeto::Objeto(int x, int y, int w, int h) {

    pos_x = x;
    pos_y = y;
    width = w;
    height = h;

    rect.x = x;
    rect.y = y;
    rect.w = w;
    rect.h = h;

}

const SDL_Rect* Objeto::get_rect() {

    return &rect;

}

void Objeto::draw(Renderer *r) {

    r->drawRect(&rect);

}

float Objeto::get_pos_x() {

    return pos_x;

}
float Objeto::get_pos_y() {

    return pos_y;

}

int Objeto::get_width() {

    return width;

}

int Objeto::get_height() {

    return height;

}