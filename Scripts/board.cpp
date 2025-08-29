#include "board.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

float squareWidth = 100.f;
float squareHeight = 100.f;

void createBoard(RenderWindow &window) {
    RectangleShape square(Vector2f(squareWidth, squareHeight));
    square.setOutlineThickness(3.f);       // 3-pixel outline
    square.setOutlineColor(Color::Black);  // outline color

    Color lightSquare(240, 217, 181); // light cream
    Color darkSquare(181, 136, 99);   // light brown

    for (int row = 0; row < 8; row++) {
        for (int col = 0; col < 8; col++) {
            float posX = col * squareWidth;
            float posY = row * squareHeight;

            square.setPosition(posX, posY);

            // Alternate colors like a chessboard
            if ((row + col) % 2 == 0)
                square.setFillColor(lightSquare);
            else
                square.setFillColor(darkSquare);

            window.draw(square);
        }
    }
}
