#include "Player.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
    this->rect.setSize(Vector2f(this->width, this->height));
    this->rect.setFillColor(this->color);
}

void Player::setSize(int w, int h) {
    this->width = w;
    this->height = h;
}

void Player::setDir(int d) {
    this->dir = d;
}

void Player::move() {
    int dy = 5;
    if (this->dir == Player::UP) {
        if (this->y - dy >= 0) {
            this->y -= dy;
        }
    }
    if (this->dir == Player::DOWN) {
        if (this->y + dy <= 600 - this->height) {
            this->y += dy;
        }
    }

    this->rect.setPosition(Vector2f(this->x, this->y));
}

void Player::draw(RenderWindow *window) {
    this->move();
    window->draw(this->rect);
}
