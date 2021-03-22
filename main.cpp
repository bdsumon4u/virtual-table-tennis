#include "Config.h"
#include "Player.h"
#include "Net.h"
#include "Ball.h"

int main() {
    RenderWindow window(sf::VideoMode(800, 600), "Ping Pong");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Player pLeft(10, 10), pRight(775, 490);
    Net net(2, 10);
    Ball ball(15);

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

        if (ball.getPosition().x - 2 * ball.r < 800 / 2 - 1 && ball.move(&pLeft)) {
            pRight.score++;
        } else if (ball.getPosition().x > 800 / 2 - 1 && ball.move(&pRight)){
            pLeft.score++;
        }

        cout << pLeft.score << " == " << pRight.score << endl;

        window.clear();

        net.draw(&window);
        pLeft.draw(&window);
        ball.draw(&window);
        pRight.draw(&window);

        window.display();
    }

    return 0;
}
