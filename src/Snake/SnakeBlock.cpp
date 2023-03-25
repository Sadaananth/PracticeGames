#include "SnakeBlock.hpp"

SnakeBlock::SnakeBlock(uint32_t size)
{
    mShape.setSize(sf::Vector2f(size, size));
    mShape.setFillColor(sf::Color::Green);
}

SnakeBlock::~SnakeBlock()
{

}

void SnakeBlock::setPosition(sf::Vector2f& position)
{
    mShape.setPosition(position);
}

sf::Vector2f SnakeBlock::getPosition() const
{
    return mShape.getPosition();
}

void SnakeBlock::draw(sf::RenderWindow& window) const
{
    window.draw(mShape);
}
