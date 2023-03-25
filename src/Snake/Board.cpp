#include "Board.hpp"

 #include <experimental/random>

constexpr uint32_t BOARD_WIDTH = 600;
constexpr uint32_t BOARD_HEIGHT = 600;
constexpr uint32_t CELL_WIDTH = 30;
constexpr uint32_t CELL_COUNT = (BOARD_WIDTH * BOARD_HEIGHT) / (CELL_WIDTH * CELL_WIDTH);

Board::Board() : mSnake(Snake::instance())
{
    mSnake.setSize(CELL_WIDTH);

    //auto random = std::experimental::randint(0, CELL_COUNT);
    mBall.setRadius(CELL_WIDTH / 2);
    mBall.setFillColor(sf::Color::White);

    sf::Vector2f position;
    position.x = 0;
    position.y = 0;
    mBall.setPosition(position);
}

void Board::draw(sf::RenderWindow& window)
{
    window.draw(mBall);
    mSnake.draw(window);
}


void Board::mouseButtonPressed(const sf::Event& event)
{
    switch(event.key.code) {
        case sf::Keyboard::Up:
            break;
        case sf::Keyboard::Down:
            break;
        case sf::Keyboard::Left:
            break;
        case sf::Keyboard::Right:
            break;
        default:
            break;
    }
}

uint32_t Board::width() const
{
    return BOARD_WIDTH;
}

uint32_t Board::height() const
{
    return BOARD_HEIGHT;
}
