#include "Snake.hpp"
#include "src/Logger.hpp"

using namespace Sada;

Snake& Snake::instance(uint32_t size, sf::Vector2f boardSize)
{
    static Snake snake(size, boardSize);
    return snake;
}

Snake::Snake(uint32_t size, sf::Vector2f boardSize)
{
    mBlockSize = size;
    mBoardSize = boardSize;

    createAndAddBlock(sf::Vector2f(mBlockSize, mBlockSize));
}

void Snake::growSnake()
{
    sf::Vector2f tailPosition(mBlockSize, mBlockSize);
    for(const auto& block : mSnakeBlocks) {
        tailPosition = block.getPosition();
    }
    tailPosition.x = tailPosition.x + mBlockSize;
    tailPosition.y = tailPosition.y;
    createAndAddBlock(tailPosition, sf::Color::Green);
}

void Snake::draw(sf::RenderWindow& window)
{
    advance();
    for(const auto& block : mSnakeBlocks) {
        block.draw(window);
    }
}

void Snake::faceUp()
{
    if(mXDirection == 0 && mYDirection == 1) {
        return;
    }
    mXDirection = 0;
    mYDirection = -1;
}

void Snake::faceDown()
{
    if(mXDirection == 0 && mYDirection == -1) {
        return;
    }
    mXDirection = 0;
    mYDirection = 1;
}

void Snake::faceLeft()
{
    if(mXDirection == 1 && mYDirection == 0) {
        return;
    }
    mXDirection = -1;
    mYDirection = 0;
}

void Snake::faceRight()
{
    if(mXDirection == -1 && mYDirection == 0) {
        return;
    }
    mXDirection = 1;
    mYDirection = 0;
}

void Snake::advance()
{
    sf::Vector2f previousPosition;
    auto snakeBlockItr = mSnakeBlocks.begin();
    if(snakeBlockItr != mSnakeBlocks.end()) {
        auto position = snakeBlockItr->getPosition();
        previousPosition = position;

        position.x = position.x + mXDirection * static_cast<int>(mBlockSize);
        position.y = position.y + mYDirection * static_cast<int>(mBlockSize);

        if(position.x < 0) {
            position.x = mBoardSize.x - mBlockSize;
        } else if(position.x >= mBoardSize.x) {
            position.x = 0;
        } else if(position.y < 0) {
            position.y = mBoardSize.y - mBlockSize;
        } else if(position.y >= mBoardSize.y) {
            position.y = 0;
        }
        snakeBlockItr->setPosition(position);
    }
    for(++snakeBlockItr; snakeBlockItr != mSnakeBlocks.end(); snakeBlockItr++) {
        auto position = snakeBlockItr->getPosition();
        snakeBlockItr->setPosition(previousPosition);
        previousPosition = position;
    }
}

void Snake::createAndAddBlock(sf::Vector2f position, sf::Color color)
{
    SnakeBlock snakeBlock(mBlockSize);
    snakeBlock.setPosition(position);
    snakeBlock.setColor(color);
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
        // LOG_DEBUG << "Body position x:" << position.x << " y:" << position.y;
        // LOG_DEBUG << "Head position x:" << headPosition.x << " y:" << headPosition.y;
        if(headPosition.x >= position.x && headPosition.x < (position.x + mBlockSize)
            && headPosition.y >= position.y && headPosition.y < (position.y + mBlockSize)) {
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
