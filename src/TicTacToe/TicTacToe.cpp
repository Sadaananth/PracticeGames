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

    if(m_now_x) {
        x_object local_x_object;
        local_x_object.x[0].setSize(sf::Vector2f(10, cell_height));
        local_x_object.x[0].setFillColor(sf::Color::Yellow);
        local_x_object.x[0].rotate(-45);

        local_x_object.x[1].setSize(sf::Vector2f(10, cell_height));
        local_x_object.x[1].setFillColor(sf::Color::Yellow);
        local_x_object.x[1].rotate(45);


        if(x <= cell_width && y <= cell_height ) {
            // 0
            local_x_object.x[0].setPosition(sf::Vector2f(offset, offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width - offset, offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y <= cell_height ) {
            // 1
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + offset, offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width - offset, offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y <= cell_height ) {
            // 2
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + cell_width - offset, offset));
        } else if(x <= cell_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height) {
            local_x_object.x[0].setPosition(sf::Vector2f(offset, cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width - offset, cell_height + space_width + offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height ) {
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + offset, cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width - offset, cell_height + space_width + offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height ) {
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + cell_width - offset, cell_height + space_width + offset));
        } else if(x <= cell_width && y > cell_height + space_width + cell_height + space_width) {
            local_x_object.x[0].setPosition(sf::Vector2f(offset, cell_height + space_width + cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width - offset, cell_height + space_width + cell_height + space_width + offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y > cell_height + space_width + cell_height + space_width ) {
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + offset, cell_height + space_width + cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width - offset, cell_height + space_width + cell_height + space_width + offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y > cell_height + space_width + cell_height + space_width ) {
            local_x_object.x[0].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, cell_height + space_width + cell_height + space_width + offset));
            local_x_object.x[1].setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + cell_width - offset, cell_height + space_width + cell_height + space_width + offset));
        }

        m_x_list.emplace_back(local_x_object);
    } else {
        sf::CircleShape circle((cell_width / 2) - 40);
        circle.setFillColor(sf::Color::Black);
        circle.setOutlineThickness(10);
        circle.setOutlineColor(sf::Color::Yellow);

        if(x <= cell_width && y <= cell_height ) {
            // 0
            circle.setPosition(sf::Vector2f(offset, offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y <= cell_height ) {
            // 1
            circle.setPosition(sf::Vector2f(cell_width + space_width + offset, offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y <= cell_height ) {
            // 2
            circle.setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, offset));
        } else if(x <= cell_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height) {
            circle.setPosition(sf::Vector2f(offset, cell_height + space_width + offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height ) {
            circle.setPosition(sf::Vector2f(cell_width + space_width + offset, cell_height + space_width + offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y > cell_height + space_width && y <= cell_height + space_width + cell_height ) {
            circle.setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, cell_height + space_width + offset));
        } else if(x <= cell_width && y > cell_height + space_width + cell_height + space_width) {
            circle.setPosition(sf::Vector2f(offset, cell_height + space_width + cell_height + space_width + offset));
        } else if(x > cell_width + space_width && x <= cell_width + space_width + cell_width && y > cell_height + space_width + cell_height + space_width ) {
            circle.setPosition(sf::Vector2f(cell_width + space_width + offset, cell_height + space_width + cell_height + space_width + offset));
        } else if(x > cell_width + space_width + cell_width + space_width && y > cell_height + space_width + cell_height + space_width ) {
            circle.setPosition(sf::Vector2f(cell_width + space_width + cell_width + space_width + offset, cell_height + space_width + cell_height + space_width + offset));
        }

        m_o_list.emplace_back(circle);
    }

    m_now_x = !m_now_x;
}
