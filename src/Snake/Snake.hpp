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

private:
    Snake(uint32_t size);
    void advance();
    void createAndAddBlock();

    std::vector<SnakeBlock> mSnakeBlocks;

    uint32_t mBlockSize;
    uint32_t mXDirection{1};
    uint32_t mYDirection{1};
};
