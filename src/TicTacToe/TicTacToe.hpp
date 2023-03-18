#pragma once

#include <SFML/Graphics.hpp>

class TicTacToe
{
public:
    TicTacToe();
    ~TicTacToe();

    uint32_t width() const;
    uint32_t height() const;
    void draw(sf::RenderWindow& window);
    void mouseButtonPressed(const sf::Event& event);

private:
    const uint32_t cell_height{200};
    const uint32_t cell_width{200};
    const uint32_t space_width{20};

    sf::RectangleShape m_firstVerticalLine;
    sf::RectangleShape m_secondVerticalLine;
    sf::RectangleShape m_firstHorizontalLine;
    sf::RectangleShape m_secondHorizontalLine;

    std::vector<sf::CircleShape> m_o_list;
};
