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

void Objeto::move_x(float v) {

    pos_x += v;
    rect.x = pos_x;

}

void Objeto::move_y(float v) {

    pos_y += v;
    rect.y = pos_y;

}

bool Objeto::verf_colisao(Objeto *obj) {

    int leftA, leftB;
    int rightA, rightB;
    int topA, topB;
    int bottomA, bottomB;

    leftA = obj->get_pos_x();
    rightA = obj->get_pos_x() + obj->get_width();
    topA = obj->get_pos_y();
    bottomA = obj->get_pos_y() + obj->get_height();

    leftB = pos_x;
    rightB = pos_x + width;
    topB = pos_y;
    bottomB = pos_y + height;

    if( bottomA <= topB )
    {
        return 0;
    }

    if( topA >= bottomB )
    {
        return 0;
    }

    if( rightA <= leftB )
    {
        return 0;
    }

    if( leftA >= rightB )
    {
        return 0;
    }

    return 1;

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