#include "SnakeBlock.hpp"

SnakeBlock::SnakeBlock(uint32_t size)
{
    mShape.setRadius(size / 2);
    mShape.setPosition(sf::Vector2f(size, size));
}

SnakeBlock::~SnakeBlock()
{

}

void SnakeBlock::setPosition(sf::Vector2f& position)
{
    mShape.setPosition(position);
}

void SnakeBlock::setColor(sf::Color color)
{
    mShape.setFillColor(color);
}

sf::Vector2f SnakeBlock::getPosition() const
{
    return mShape.getPosition();
}

void SnakeBlock::draw(sf::RenderWindow& window) const
{
    window.draw(mShape);
}
