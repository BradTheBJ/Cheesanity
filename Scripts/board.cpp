#include "board.h"
#include <SFML/Graphics.hpp>

using namespace sf;

float squareWidth = 100.f;
float squareHeight = 100.f;

// ID → top-left position
std::map<std::string, sf::Vector2f> squarePositions;

void createBoard(RenderWindow &window) {
    RectangleShape square(Vector2f(squareWidth, squareHeight));
    square.setOutlineThickness(3.f);
    square.setOutlineColor(Color::Black);

    Color lightSquare(240, 217, 181);
    Color darkSquare(181, 136, 99);

    const std::string letters = "ABCDEFGH";

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            float posX = col * squareWidth;
            float posY = row * squareHeight;

            square.setPosition(posX, posY);
            square.setFillColor((row + col) % 2 == 0 ? lightSquare : darkSquare);

            window.draw(square);

            // create ID like "H3" (col letter + row number)
            std::string id = letters[col] + std::to_string(8 - row); // row 0 = 8
            squarePositions[id] = Vector2f(posX, posY);
        }
    }
}

// helper to get square position by ID
Vector2f getSquarePosition(const std::string &id) {
    if (squarePositions.count(id))
        return squarePositions[id];
    return Vector2f(-1.f, -1.f); // invalid square
}

