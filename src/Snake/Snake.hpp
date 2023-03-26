#pragma once

#include "SnakeBlock.hpp"

#include <vector>

class Snake
{
public:
    static Snake& instance(uint32_t size);

    void growSnake();

    void draw(sf::RenderWindow& window) const;

    void faceUp();
    void faceDown();
    void faceLeft();
    void faceRight();

    bool isSnakeCollided() const;
    sf::Vector2f getHeadPosition() const;

private:
    Snake(uint32_t size);
    void advance(int xdirection, int ydirection);
    void createAndAddBlock();

    std::vector<SnakeBlock> mSnakeBlocks;

    uint32_t mBlockSize;
};
