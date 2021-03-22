#include "SFML/Graphics.hpp"
#include "iostream"

using sf::RenderWindow;
using sf::Event;
using sf::Color;
using sf::RectangleShape;
using sf::Vector2f;
using sf::CircleShape;

void drawRect(RenderWindow *window, int x, int y, int w, int h, Color color = Color::White);
void drawCircle(RenderWindow *window, int x, int y, int r, Color color = Color::White);

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "SFML APP");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    while (window.isOpen())
    {
        Event ev{};

        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed) {
                window.close();
            }
        }

        window.clear();
        drawRect(&window, 40, 50, 20, 100);
        drawCircle(&window, 385, 285, 15);
        drawRect(&window, 740, 450, 20, 100);
        window.display();
    }

    return 0;
}

void drawRect(RenderWindow *window, int x, int y, int w, int h, Color color) {
    RectangleShape rect(Vector2f(w, h));
    rect.setPosition(Vector2f(x, y));
    rect.setFillColor(color);
    window->draw(rect);
}

void drawCircle(RenderWindow *window, int x, int y, int r, Color color) {
    CircleShape circle((float) r);
    circle.setPosition(Vector2f(x, y));
    circle.setFillColor(color);
    window->draw(circle);
}
