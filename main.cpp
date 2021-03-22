#include "Config.h"
#include "Player.h"

void drawCircle(RenderWindow *window, int x, int y, int r, Color color = Color::White);

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "Ping Pong");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Player pLeft(10, 10), pRight(775, 490);

    while (window.isOpen())
    {
        Event ev{};

        while (window.pollEvent(ev))
        {
            if (ev.type == Event::Closed) {
                window.close();
            }

            if (ev.type == Event::KeyPressed) {
                if (ev.key.code == Keyboard::Key::W) {
                    pLeft.setDir(Player::UP);
                } else if (ev.key.code == Keyboard::Key::S) {
                    pLeft.setDir(Player::DOWN);
                } else if (ev.key.code == Keyboard::Key::O) {
                    pRight.setDir(Player::UP);
                } else if (ev.key.code == Keyboard::Key::L) {
                    pRight.setDir(Player::DOWN);
                }
            } else if (ev.type == Event::KeyReleased) {
                if (ev.key.code == Keyboard::Key::W || ev.key.code == Keyboard::Key::S) {
                    pLeft.setDir(Player::NONE);
                } else if (ev.key.code == Keyboard::Key::O || ev.key.code == Keyboard::Key::L) {
                    pRight.setDir(Player::NONE);
                }
            }
        }

        window.clear();
        pLeft.draw(&window);
        drawCircle(&window, 385, 285, 15);
        pRight.draw(&window);
        window.display();
    }

    return 0;
}

void drawCircle(RenderWindow *window, int x, int y, int r, Color color) {
    CircleShape circle((float) r);
    circle.setPosition(Vector2f(x, y));
    circle.setFillColor(color);
    window->draw(circle);
}
