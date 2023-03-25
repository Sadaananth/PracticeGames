#include "Board.hpp"

constexpr uint32_t BOARD_WIDTH = 600;
constexpr uint32_t BOARD_HEIGHT = 600;
constexpr uint32_t CELL_WIDTH = 30;
constexpr uint32_t CELL_COUNT = (BOARD_WIDTH * BOARD_HEIGHT) / (CELL_WIDTH * CELL_WIDTH);
constexpr uint32_t BALL_RADIUS = 8;
constexpr uint32_t BALL_CELL_OFFSET = CELL_WIDTH - (2 * BALL_RADIUS);

Board::Board() : mSnake(Snake::instance(CELL_WIDTH))
{
    mBall.setRadius(BALL_RADIUS);
    mBall.setFillColor(sf::Color::White);

    sf::Vector2f position;
    position.x = BALL_CELL_OFFSET / 2;
    position.y = BALL_CELL_OFFSET / 2;
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

void Board::checkAndHandleBallEaten()
{
    // ball eaten
    mSnake.growSnake();
}

uint32_t Board::width() const
{
    return BOARD_WIDTH;
}

uint32_t Board::height() const
{
    return BOARD_HEIGHT;
}
