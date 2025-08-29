#include "pawn.h"
#include <iostream>

sf::Texture Pawn::texture; // static definition

Pawn::Pawn(float x, float y) {
    if (texture.getSize().x == 0) { // load only once
        if (!texture.loadFromFile("Sprites/White Pawn.png")) {
            std::cout << "Error loading texture: White pawn\n";
        }
    }
    sprite.setTexture(texture);

    // center origin for proper mouse alignment
    sprite.setOrigin(texture.getSize().x / 2.f, texture.getSize().y / 2.f);

    sprite.setPosition(x, y);
}

void Pawn::draw(sf::RenderWindow &window) {
    window.draw(sprite);
}

// Toggle follow state if clicked
void Pawn::handleClick(sf::Vector2i mousePos) {
    if (sprite.getGlobalBounds().contains(static_cast<sf::Vector2f>(mousePos))) {
        followingMouse = !followingMouse;
    }
}

bool Pawn::isFollowing() const {
    return followingMouse;
}

// Update position to follow mouse
void Pawn::followMouse(sf::Vector2i mousePos) {
    if (followingMouse) {
        sprite.setPosition(static_cast<float>(mousePos.x),
                           static_cast<float>(mousePos.y));
    }
}

// ---------- simple functions ----------
sf::Vector2f Pawn::getPosition() const {
    return sprite.getPosition();
}

void Pawn::move(float dx, float dy) {
    sprite.move(dx, dy);
}

void Pawn::setPosition(float x, float y) {
    sprite.setPosition(x, y);
}
