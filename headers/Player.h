#include "Config.h"

#ifndef PINGPONG_PLAYER_H
#define PINGPONG_PLAYER_H


class Player {
private:
    int x, y, width = 15, height = 100, dir = 0, score = 0;
    Color color = Color::White;
    RectangleShape rect;
public:
    static const int UP = 1, DOWN = 2, NONE = 0;
    Player(int x, int y);
    void setSize(int w, int h);
    void setDir(int d = Player::NONE);
    void move();
    void draw(RenderWindow *window);
};


#endif //PINGPONG_PLAYER_H
