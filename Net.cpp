#include "Net.h"

Net::Net(int w, int h) {
    this->width = w;
    this->height = h;
    this->rect.setSize(Vector2f(this->width, this->height));
    this->rect.setFillColor(this->color);
}

void Net::draw(RenderWindow *window) {
    for (int i = 0; i < 600; i += 16) {
        this->rect.setPosition(Vector2f((float) 800 / 2 - 1, i));
        window->draw(this->rect);
    }
}
