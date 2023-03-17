#include "TicTacToe.hpp"
TicTacToe::TicTacToe()
{
    firstVerticalLine.setSize(sf::Vector2f(20, 480));
    firstVerticalLine.setPosition(sf::Vector2f(200, 0));
    firstVerticalLine.setFillColor(sf::Color::White);
    
    secondVerticalLine.setSize(sf::Vector2f(20, 480));
    secondVerticalLine.setPosition(sf::Vector2f(420, 0));
    secondVerticalLine.setFillColor(sf::Color::White);
    
    firstHorizontalLine.setSize(sf::Vector2f(640, 30));
    firstHorizontalLine.setPosition(sf::Vector2f(0, 140));
    firstHorizontalLine.setFillColor(sf::Color::White);
    
    secondHorizontalLine.setSize(sf::Vector2f(640, 30));
    secondHorizontalLine.setPosition(sf::Vector2f(0, 310));
    secondHorizontalLine.setFillColor(sf::Color::White);
}

TicTacToe::~TicTacToe()
{

}

void TicTacToe::draw(sf::RenderWindow& window)
{
    window.draw(firstVerticalLine);
    window.draw(secondVerticalLine);
    window.draw(firstHorizontalLine);
    window.draw(secondHorizontalLine);
}
