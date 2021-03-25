#include "Config.h"
#include "Player.h"
#include "Net.h"
#include "Ball.h"

int main() {
    bool is_win = false;
    int win_point = 10;
    RenderWindow window(sf::VideoMode(800, 600), "Virtual Table Tennis");
    window.setFramerateLimit(60);
    window.setKeyRepeatEnabled(false);

    Player pLeft(10, 10), pRight(775, 490);
    Net net(2, 10);
    Ball ball(15);

    Font font;
    if (!font.loadFromFile("./assets/fonts/FreeSans.ttf")) {
        //
    }
    Text win, playerOne, playerTwo;
    win.setFont(font);
    win.setCharacterSize(50);
    win.setFillColor(Color::White);
    win.setPosition(100, 500);

    playerOne.setFont(font);
    playerOne.setCharacterSize(15);
    playerOne.setFillColor(Color::White);
    playerOne.setString("Player One");
    playerOne.setPosition(800 / 4 - 32, 600 / 10 - 20);

    playerTwo.setFont(font);
    playerTwo.setCharacterSize(15);
    playerTwo.setFillColor(Color::White);
    playerTwo.setString("Player Two");
    playerTwo.setPosition(3 * 800 / 4 - 32, 600 / 10 - 20);

    sf::Rect<float> bounds;
    sf::Texture gameWin;
    if (!gameWin.loadFromFile("assets/imgs/game-win.png")) {
        cout << "Game Win Couldn't Found." << endl;
        exit(1);
    }
    sf::Sprite sGameWin(gameWin);
    sGameWin.setColor(sf::Color::Red);
    bounds = sGameWin.getLocalBounds();
    sGameWin.setOrigin(bounds.width / 2.0, bounds.height / 2.0);
    sGameWin.setPosition(800 / 2.0, 600 / 2.0);

    pLeft.scorePos(800 / 4, 600 / 10);
    pRight.scorePos(3 * 800 / 4, 600 / 10);

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

        if (!is_win) {
            if (ball.getPosition().x - 2 * ball.r < 800 / 2 - 1 && ball.move(&pLeft)) {
                pRight.score++;
            } else if (ball.getPosition().x > 800 / 2 - 1 && ball.move(&pRight)){
                pLeft.score++;
            }
        }

        if (pLeft.score >= win_point) {
            is_win = true;
//            cout << "Player One Won The Game" << endl;
            win.setString("Player One Won The Game");
        } else if (pRight.score >= win_point) {
            is_win = true;
//            cout << "Player Tow Won The Game" << endl;
            win.setString("Player Tow Won The Game");
        }

        window.clear();

        window.draw(playerOne);
        window.draw(playerTwo);

        net.draw(&window);
        pLeft.draw(&window);
        if (!is_win) ball.draw(&window);
        pRight.draw(&window);

        if (is_win) {
            window.draw(sGameWin);
            window.draw(win);
        }

        window.display();
    }

    return 0;
}
