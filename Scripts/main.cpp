#include <SFML/Graphics.hpp>
#include "board.h"
#include "letters.h"
#include "pawn.h"
#include <vector>
#include <iostream>

using namespace sf;

int main() {
    RenderWindow window(VideoMode(800, 800), "Chessanity");

    // manually create 8 pawns on row 6 (white pawns)
    std::vector<Pawn> pawns;
    float startX = 50.f;    // center of first square
    float startY = 645.f;   // row 6 Y position
    for (int i = 0; i < 8; i++)
        pawns.emplace_back(startX + i * 100.f, startY);

    while (window.isOpen()) {
        Event event;
        while (window.pollEvent(event)) {
            if (event.type == Event::Closed)
                window.close();

            if (event.type == Event::MouseButtonPressed) {
                Vector2i mousePos = Mouse::getPosition(window);

                // check all squares
                for (const auto& [id, pos] : squarePositions) {
                    FloatRect rect(pos.x, pos.y, squareWidth, squareHeight);
                    if (rect.contains(static_cast<float>(mousePos.x), static_cast<float>(mousePos.y))) {
                        Vector2f center = pos + Vector2f(squareWidth / 2.f, squareHeight / 2.f);
                        std::cout << "Clicked square: " << id << std::endl;
                        std::cout << "Top-left: x=" << pos.x << ", y=" << pos.y << std::endl;
                        std::cout << "Center:   x=" << center.x << ", y=" << center.y << std::endl;
                        break;
                    }
                }

                // toggle pawn click
                for (auto &pawn : pawns)
                    pawn.handleClick(mousePos);
            }
        }

        // update pawns following mouse
        Vector2i mousePos = Mouse::getPosition(window);
        for (auto &pawn : pawns)
            pawn.followMouse(mousePos);

        // draw board and pawns
        window.clear();
        createBoard(window);
        createNotation(window);
        for (auto &pawn : pawns)
            pawn.draw(window);
        window.display();
    }

    return 0;
}
