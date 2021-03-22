#include "SFML/Graphics.hpp"
#include "iostream"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML APP");

    std::cout << "Playing" << std::endl;
    while (window.isOpen())
    {
        sf::Event ev{};

        while (window.pollEvent(ev))
        {
            if (ev.type == sf::Event::Closed) {
                window.close();
                std::cout << "Closed" << std::endl;
            }
        }

        window.clear();
        window.display();
    }

    return 0;
}
