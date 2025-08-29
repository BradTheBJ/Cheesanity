#pragma once
#include <SFML/Graphics.hpp>
#include <map>
#include <string>

extern float squareWidth;
extern float squareHeight;

// map of square ID → position of top-left corner
extern std::map<std::string, sf::Vector2f> squarePositions;

void createBoard(sf::RenderWindow &window);
sf::Vector2f getSquarePosition(const std::string &id);
