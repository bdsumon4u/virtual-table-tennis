#include "Ball.h"

Ball::Ball(int r) {
    this->r = r;
    this->toCenter();
    this->circle.setRadius((float) r);
    this->circle.setFillColor(this->color);
}

void Ball::toCenter() {
    int x = 800 / 2 - this->r, y = 600 / 2 - this->r;
    this->circle.setPosition(Vector2f(x, y));
}

Vector2<float> Ball::getPosition() {
    return this->circle.getPosition();
}

bool Ball::move(Player *player) {
    bool is = false;
    Vector2<float> pos = this->getPosition();

    if (pos.y <= 0) {
        this->dy = 5;
    } else if (pos.y >= (float) (600 - this->r)) {
        this->dy = -5;
    }

    if (this->collision(player)) {
        this->dx = -this->dx;
    } else if (pos.x <= 0 || pos.x >= 800) {
        is = true;
        this->toCenter();
    }

    this->circle.move(Vector2f(dx, dy));

    return is;
}

bool Ball::collision(Player *player) {
    int d = 2 * this->r;
    Vector2<float> pos = this->getPosition();

    return pos.x + d > player->x
         && pos.y + d > player->y
         && pos.x < player->x + player->width
         && pos.y < player->y + player->height;
}

void Ball::draw(RenderWindow *window) {
    window->draw(this->circle);
}
