#include "Player.h"

Player::Player(int x, int y) {
    this->x = x;
    this->y = y;
    this->rect.setSize(Vector2f(this->width, this->height));
    this->rect.setFillColor(this->color);

    if (!this->font.loadFromFile("./assets/fonts/FreeSans.ttf")) {
        exit(0);
    }
    this->scoreText.setFont(this->font);
    this->scoreText.setFillColor(Color::Red);
    this->scoreText.setCharacterSize(20);
    this->scoreText.setString("0");
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

void Player::scorePos(int l, int t) {
    this->scoreText.setPosition(Vector2f(l, t));
}

void Player::draw(RenderWindow *window) {
    this->move();

    sprintf(this->score_str, "%d", this->score);
    this->scoreText.setString(this->score_str);
    window->draw(this->scoreText);

    window->draw(this->rect);
}
