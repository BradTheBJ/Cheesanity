#include "board.h"

float squareWidth = 100;
float squareHeight = 100;
float columns = 8;
float rows = 8;

void createBoard(RenderWindow &window) {
    float PosX = 0;
    float PosY = 0;
    RectangleShape square(Vector2f(squareWidth, squareHeight));
    for (int i = 0; i < 8; i++) {
        square.setPosition(PosX, PosY);
        window.draw(square);
        PosX += squareWidth;
        PosY += squareHeight;
    }
}
