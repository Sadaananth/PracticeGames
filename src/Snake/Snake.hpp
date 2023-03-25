#pragma once

#include <SFML/Graphics.hpp>

#include <vector>

class Snake
{
public:
    static Snake& instance();

    void setSize(uint32_t size);
    void growSnake();

    void draw(sf::RenderWindow& window) const;

private:
    Snake();

    uint32_t mBlockSize;
    std::vector<sf::RectangleShape> mSnakeBlocks;
};
