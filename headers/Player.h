#include "Config.h"

#ifndef PINGPONG_PLAYER_H
#define PINGPONG_PLAYER_H


class Player {
private:
    Color color = Color::White;
    char score_str[4]{};
    RectangleShape rect;
    Text scoreText;
    Font font;
public:
    int x, y, width = 15, height = 100, dir = 0, score = 0;
    static const int UP = 1, DOWN = 2, NONE = 0;
    Player(int x, int y);
    void setSize(int w, int h);
    void setDir(int d = Player::NONE);
    void move();
    void scorePos(int x, int y);
    void draw(RenderWindow *window);
};


#endif //PINGPONG_PLAYER_H
