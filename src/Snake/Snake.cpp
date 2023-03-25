#include "Snake.hpp"

Snake& Snake::instance()
{
    static Snake snake;
    return snake;
}

Snake::Snake()
{
    sf::RectangleShape block;
    block.setFillColor(sf::Color::Green);
    block.setPosition(sf::Vector2f(100, 100));

    mSnakeBlocks.emplace_back(block);
}

void Snake::setSize(uint32_t size)
{
    mBlockSize = size;
    for(auto& block : mSnakeBlocks) {
        block.setSize(sf::Vector2f(mBlockSize, mBlockSize));
    }
}

void Snake::growSnake()
{
    sf::RectangleShape block(sf::Vector2f(mBlockSize, mBlockSize));
    block.setFillColor(sf::Color::Green);

    mSnakeBlocks.emplace_back(block);
}

void Snake::draw(sf::RenderWindow& window) const
{
    for(const auto& block : mSnakeBlocks) {
        window.draw(block);
    }
}
