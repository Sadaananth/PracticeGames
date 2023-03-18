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

    for(uint8_t index = 0; index < m_box.size(); index++) {
        m_box[index].left = (index % 3) * cell_width + (index % 3) * space_width;
        m_box[index].right = m_box[index].left + cell_width;
        m_box[index].top = (index / 3) * cell_height + (index / 3) * space_width;
        m_box[index].bottom = m_box[index].top + cell_height;
    }
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
        window.draw(circle.o);
    }

    for(auto& x_ : m_x_list) {
        window.draw(x_.x[0]);
        window.draw(x_.x[1]);
    }
}

void TicTacToe::mouseButtonPressed(const sf::Event& event)
{
    std::cout << "Mouse Button Pressed" << std::endl;
    std::cout << "x:" << event.mouseButton.x << " y:" << event.mouseButton.y << std::endl;
    uint32_t x = event.mouseButton.x;
    uint32_t y = event.mouseButton.y;
    uint32_t offset = 20;

    if(m_x_list.size() + m_o_list.size() >= 9) {
        return;
    }

    if(m_now_x) {
        x_object local_x_object;
        local_x_object.x[0].setSize(sf::Vector2f(10, cell_height + 20));
        local_x_object.x[0].setFillColor(sf::Color::Yellow);
        local_x_object.x[0].rotate(-45);

        local_x_object.x[1].setSize(sf::Vector2f(10, cell_height + 20));
        local_x_object.x[1].setFillColor(sf::Color::Yellow);
        local_x_object.x[1].rotate(45);

        auto index = getBoxIndex(x, y);
        if(index < 0) {
            return;
        }
        local_x_object.x[0].setPosition(sf::Vector2f(m_box[index].left + offset, m_box[index].top + offset));
        local_x_object.x[1].setPosition(sf::Vector2f(m_box[index].right - offset, m_box[index].top + offset));
        local_x_object.index = index;

        m_x_list.emplace_back(local_x_object);
    } else {
        o_object local_o_object;
        local_o_object.o.setRadius((cell_width / 2) - 20);
        local_o_object.o.setFillColor(sf::Color::Black);
        local_o_object.o.setOutlineThickness(10);
        local_o_object.o.setOutlineColor(sf::Color::Yellow);

        auto index = getBoxIndex(x, y);
        if(index < 0) {
            return;
        }
        local_o_object.o.setPosition(sf::Vector2f(sf::Vector2f(m_box[index].left + offset, m_box[index].top + offset)));
        local_o_object.index = index;

        m_o_list.emplace_back(local_o_object);
    }

    m_now_x = !m_now_x;
}

uint8_t TicTacToe::getBoxIndex(uint32_t x, uint32_t y)
{
    for(uint8_t index = 0; index < m_box.size(); index++) {
        if(x > m_box[index].left &&
            x <= m_box[index].right && 
            y > m_box[index].top &&
            y <= m_box[index].bottom)
            {
                return index;
            }
    }

    std::cout << "returning default" << std::endl;
    return -1;
}

void TicTacToe::validateWin()
{
    if(m_x_list.size() < 3 && m_o_list.size() < 3) {
        return;
    }

    if(m_now_x) {
        
    }
}
