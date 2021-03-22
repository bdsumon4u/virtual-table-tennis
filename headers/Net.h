#include "Config.h"

#ifndef PINGPONG_NET_H
#define PINGPONG_NET_H


class Net {
private:
    int width, height;
    Color color = Color::White;
    RectangleShape rect;
public:
    Net(int w, int h);
    void draw(RenderWindow *window);
};


#endif //PINGPONG_NET_H
