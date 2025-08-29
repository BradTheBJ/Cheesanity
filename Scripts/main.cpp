#include <SFML/Graphics.hpp>
#include "board.h"
#include "letters.h"
using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 800), "Cheesanity");

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        createBoard(window); // texture handled inside board.cpp
        createNotation(window);
        window.display();
    }
}
