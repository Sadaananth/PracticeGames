#pragma once

#include <SFML/Graphics.hpp>

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe();

    void draw(sf::RenderWindow& window);

private:
    sf::RectangleShape firstVerticalLine;
    sf::RectangleShape secondVerticalLine;
    sf::RectangleShape firstHorizontalLine;
    sf::RectangleShape secondHorizontalLine;
};
