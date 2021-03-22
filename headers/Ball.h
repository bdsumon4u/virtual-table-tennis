#include "Config.h"
#include "Player.h"

#ifndef PINGPONG_BALL_H
#define PINGPONG_BALL_H


class Ball {
private:
    Color color = Color::White;
    CircleShape circle;
public:
    int r, dx = 3, dy = 5;
    explicit Ball(int r);
    void toCenter();
    Vector2<float> getPosition();
    bool move(Player *player);
    bool collision(Player *player);
    void draw(RenderWindow *window);
};


#endif //PINGPONG_BALL_H
