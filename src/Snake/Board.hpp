#pragma once

#include "Snake.hpp"

class Board
{
public:
    Board();
    ~Board() = default;

    void draw(sf::RenderWindow& window);

    void mouseButtonPressed(const sf::Event& event);

    uint32_t width() const;
    uint32_t height() const;
private:
    Snake& mSnake;

    sf::CircleShape mBall;
};
