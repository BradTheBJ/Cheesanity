#include "letters.h"
#include "window.h"
#include <SFML/Graphics.hpp>
#include <iostream>

using namespace sf;

void createNotation(sf::RenderWindow &window) {
    sf::Font font;
    if (!font.loadFromFile("C:\\Users\\benjo\\Downloads\\IM_Fell_English,Roboto\\IM_Fell_English\\IMFellEnglish-Italic.ttf")) {
        std::cout << "Failed to load font!" << std::endl;
        return; // only return if the font fails
    }

    char letters[8] = {'a','b','c','d','e','f','g','h'};
    int numbers[8] = {1,2,3,4,5,6,7,8};

    float lettersPosX = 80.f;
    float lettersPosY = 760.f;

    float numbersPosX = 5.f;
    float numbersPosY = 690.f;

    Text text;
    text.setFont(font);
    text.setCharacterSize(40);
    text.setFillColor(sf::Color::Black);

    for (int i = 0; i < 8; i++) {
        text.setString(letters[i]);
        text.setPosition(lettersPosX, lettersPosY);
        window.draw(text);
        lettersPosX += 100.f;
    }

    for (int i = 0; i < 8; i++) {
        text.setString(std::to_string(numbers[i]));
        text.setPosition(numbersPosX, numbersPosY);
        window.draw(text);
        numbersPosY -= 100.f;
    }

}
