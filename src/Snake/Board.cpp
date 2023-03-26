#include "Board.hpp"

#include "src/Logger.hpp"

using namespace Sada;

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
            mSnake.faceUp();
            break;
        case sf::Keyboard::Down:
            mSnake.faceDown();
            break;
        case sf::Keyboard::Left:
            mSnake.faceLeft();
            break;
        case sf::Keyboard::Right:
            mSnake.faceRight();
            break;
        default:
            break;
    }

    checkAndHandleSnakeCollided();
    checkAndHandleBallEaten();
}

void Board::checkAndHandleSnakeCollided()
{
    if(mSnake.isSnakeCollided()) {
        LOG_DEBUG << "Snake collided";
    }
}

void Board::checkAndHandleBallEaten()
{
    auto snakeHeadPosition = mSnake.getHeadPosition();
    auto ballPosition = mBall.getPosition();
    if((ballPosition.x >= snakeHeadPosition.x && ballPosition.x <= (snakeHeadPosition.x + CELL_WIDTH))
        || (ballPosition.y >= snakeHeadPosition.y && ballPosition.y <= (snakeHeadPosition.y + CELL_WIDTH))) {
            mSnake.growSnake();
            LOG_DEBUG << "Ate ball";
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
