#include "Ball.h"

Ball::Ball(int r) {
    this->x = 800 / 2 - r;
    this->y = 600 / 2 - r;
    this->circle.setRadius((float) r);
    this->circle.setFillColor(this->color);
}

void Ball::draw(RenderWindow *window) {
    circle.setPosition(Vector2f(this->x, this->y));
    window->draw(this->circle);
}
