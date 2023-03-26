#pragma once

#include "SnakeBlock.hpp"

#include <vector>

class Snake
{
public:
    static Snake& instance(uint32_t size, sf::Vector2f boardSize);

    void growSnake();

    void draw(sf::RenderWindow& window);

    void faceUp();
    void faceDown();
    void faceLeft();
    void faceRight();

    bool isSnakeCollided() const;
    sf::Vector2f getHeadPosition() const;

private:
    Snake(uint32_t size, sf::Vector2f boardSize);
    void advance();
    void createAndAddBlock(sf::Vector2f position, sf::Color color = sf::Color::Red);

    std::vector<SnakeBlock> mSnakeBlocks;

    uint32_t mBlockSize;
    sf::Vector2f mBoardSize;
    int mXDirection{1};
    int mYDirection{0};
};
