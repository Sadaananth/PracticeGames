#include "Snake.hpp"
#include "src/Logger.hpp"

using namespace Sada;

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
    advance(0, -1);
}

void Snake::faceDown()
{
    advance(0, 1);
}

void Snake::faceLeft()
{
    advance(-1, 0);
}

void Snake::faceRight()
{
    advance(1, 0);
}

void Snake::advance(int xdirection, int ydirection)
{
    sf::Vector2f previousPosition;
    auto snakeBlockItr = mSnakeBlocks.begin();
    if(snakeBlockItr != mSnakeBlocks.end()) {
        auto position = snakeBlockItr->getPosition();
        previousPosition = position;

        position.x = position.x + xdirection * static_cast<int>(mBlockSize);
        position.y = position.y + ydirection * static_cast<int>(mBlockSize);

        snakeBlockItr->setPosition(position);
    }
    for(++snakeBlockItr; snakeBlockItr != mSnakeBlocks.end(); snakeBlockItr++) {
        auto position = snakeBlockItr->getPosition();
        snakeBlockItr->setPosition(previousPosition);
        previousPosition = position;
    }
}

void Snake::createAndAddBlock()
{
    SnakeBlock snakeBlock(mBlockSize);
    mSnakeBlocks.emplace_back(std::move(snakeBlock));
}

bool Snake::isSnakeCollided() const
{
    sf::Vector2f headPosition;
    auto snakeBlockItr = mSnakeBlocks.begin();
    if(snakeBlockItr != mSnakeBlocks.end()) {
        headPosition = snakeBlockItr->getPosition();
    }

    for(++snakeBlockItr; snakeBlockItr != mSnakeBlocks.end(); snakeBlockItr++) {
        auto position = snakeBlockItr->getPosition();
        if(headPosition.x >= position.x && headPosition.x <= (position.x + mBlockSize)
            || headPosition.y >= position.y && headPosition.y <= (position.y + mBlockSize)) {
            return true;
        }
    }

    return false;
}

sf::Vector2f Snake::getHeadPosition() const
{
    sf::Vector2f headPosition;
    auto snakeBlockItr = mSnakeBlocks.begin();
    if(snakeBlockItr != mSnakeBlocks.end()) {
        headPosition = snakeBlockItr->getPosition();
    }

    return headPosition;
}
