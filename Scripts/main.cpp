#include <SFML/Graphics.hpp>
#include "board.h"

int main() {
    sf::RenderWindow window(sf::VideoMode(800, 800), "Cheesanity");
    while (window.isOpen()) {
        sf::Event event;
        while (window.pollEvent(event)) {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        window.clear();
        createBoard(window);
        window.display();
    }
}
