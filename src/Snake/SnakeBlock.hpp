#pragma once

#include <SFML/Graphics.hpp>

class SnakeBlock
{
public:
    SnakeBlock(uint32_t size);
    ~SnakeBlock();

    void setPosition(sf::Vector2f& position);
    void setColor(sf::Color color);

    sf::Vector2f getPosition() const;

    void draw(sf::RenderWindow& window) const;

private:
    uint32_t mBlockSize;

    sf::CircleShape mShape;
};
