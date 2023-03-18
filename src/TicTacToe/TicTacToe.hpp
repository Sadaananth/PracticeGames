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
    void validateWin();
    uint8_t getBoxIndex(uint32_t x, uint32_t y);
    struct Box {
        uint32_t left;
        uint32_t right;
        uint32_t top;
        uint32_t bottom;
    };
    struct o_object {
        uint8_t index;
        sf::CircleShape o;
    };
    struct x_object {
        uint8_t index;
        sf::RectangleShape x[2];
    };
    const uint32_t cell_height{200};
    const uint32_t cell_width{200};
    const uint32_t space_width{20};

    sf::RectangleShape m_firstVerticalLine;
    sf::RectangleShape m_secondVerticalLine;
    sf::RectangleShape m_firstHorizontalLine;
    sf::RectangleShape m_secondHorizontalLine;

    std::array<Box, 9> m_box;
    std::vector<o_object> m_o_list;
    std::vector<x_object> m_x_list;
    bool m_now_x{true};
};
