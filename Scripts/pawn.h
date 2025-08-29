#pragma once
#include <SFML/Graphics.hpp>

class Pawn {
public:
    static sf::Texture texture; // static definition for shared texture

    // Constructor using pixel coordinates
    Pawn(float x, float y);

    // Core pawn functions
    void draw(sf::RenderWindow &window);
    void handleClick(sf::Vector2i mousePos);
    void followMouse(sf::Vector2i mousePos);
    bool isFollowing() const;
    sf::Vector2f getPosition() const;
    void move(float dx, float dy);
    void setPosition(float x, float y);

private:
    sf::Sprite sprite;
    bool followingMouse = false;
};
