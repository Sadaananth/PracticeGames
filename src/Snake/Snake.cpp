#include "Snake.hpp"

Snake& Snake::instance(uint32_t size)
{
    static Snake snake(size);
    return snake;
}

Snake::Snake(uint32_t size)
{
    mBlockSize = size;

    createAndAddBlock();
}

void Snake::growSnake()
{
    createAndAddBlock();
}

void Snake::draw(sf::RenderWindow& window) const
{
    for(const auto& block : mSnakeBlocks) {
        block.draw(window);
    }
}

void Snake::faceUp()
{
    mXDirection = 0;
    mYDirection = -1;
}

void Snake::faceDown()
{

}

void Snake::faceLeft()
{

}

void Snake::faceRight()
{

}

void Snake::advance()
{
}

void Snake::createAndAddBlock()
{
    SnakeBlock snakeBlock(mBlockSize);
    mSnakeBlocks.emplace_back(std::move(snakeBlock));
}
