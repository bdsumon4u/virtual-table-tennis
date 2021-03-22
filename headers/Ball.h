#include "Config.h"

#ifndef PINGPONG_BALL_H
#define PINGPONG_BALL_H


class Ball {
private:
    int x, y;
    Color color = Color::White;
    CircleShape circle;
public:
    explicit Ball(int r);
    void draw(RenderWindow *window);
};


#endif //PINGPONG_BALL_H
