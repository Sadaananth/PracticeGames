#include "TicTacToe.hpp"

#include <iostream>

TicTacToe::TicTacToe()
{
    m_firstVerticalLine.setSize(sf::Vector2f(space_width, height()));
    m_firstVerticalLine.setPosition(sf::Vector2f(cell_width, 0));
    m_firstVerticalLine.setFillColor(sf::Color::White);
    
    m_secondVerticalLine.setSize(sf::Vector2f(space_width, height()));
    m_secondVerticalLine.setPosition(sf::Vector2f(cell_width + space_width + cell_width, 0));
    m_secondVerticalLine.setFillColor(sf::Color::White);
    
    m_firstHorizontalLine.setSize(sf::Vector2f(width(), space_width));
    m_firstHorizontalLine.setPosition(sf::Vector2f(0, cell_height));
    m_firstHorizontalLine.setFillColor(sf::Color::White);
    
    m_secondHorizontalLine.setSize(sf::Vector2f(width(), space_width));
    m_secondHorizontalLine.setPosition(sf::Vector2f(0, cell_height + space_width + cell_height));
    m_secondHorizontalLine.setFillColor(sf::Color::White);
}

TicTacToe::~TicTacToe()
{

}

uint32_t TicTacToe::width() const
{
    static uint32_t local_width = cell_width * 3 + 2 * space_width;
    return local_width;
}

uint32_t TicTacToe::height() const
{
    static uint32_t local_height = cell_height * 3 + 2 * space_width;
    return local_height;
}

void TicTacToe::draw(sf::RenderWindow& window)
{
    window.draw(m_firstVerticalLine);
    window.draw(m_secondVerticalLine);
    window.draw(m_firstHorizontalLine);
    window.draw(m_secondHorizontalLine);

    for(auto& circle : m_o_list) {
        window.draw(circle);
    }
}

void TicTacToe::mouseButtonPressed(const sf::Event& event)
{
    std::cout << "Mouse Button Pressed" << std::endl;
    std::cout << "x:" << event.mouseButton.x << " y:" << event.mouseButton.y << std::endl;

    sf::CircleShape circle((cell_width / 2) - 40);
    circle.setFillColor(sf::Color::Black);
    circle.setOutlineThickness(10);
    circle.setOutlineColor(sf::Color::Yellow);
    circle.setPosition(sf::Vector2f(10, 10));

    m_o_list.emplace_back(circle);
}
