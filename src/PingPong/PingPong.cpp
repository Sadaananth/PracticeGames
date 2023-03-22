#include "src/Logger.hpp"

#include "PingPong.hpp"

using namespace Sada;

PingPong::PingPong()
{
    mBall.setRadius(15);
    mBall.setFillColor(sf::Color::White);
    mBall.setPosition(sf::Vector2f(Width / 2, Height / 2));

    mLeftPaddle.setSize(sf::Vector2f(10, Height / 4));
    mLeftPaddle.setFillColor(sf::Color::White);
    mLeftPaddle.setPosition(sf::Vector2f(0, 0));
    
    mRightPaddle.setSize(sf::Vector2f(10, Height / 4));
    mRightPaddle.setFillColor(sf::Color::White);
    mRightPaddle.setPosition(sf::Vector2f(Width - 10, 0));
}

void PingPong::keyboardEventHandler(const sf::Event& event)
{
    switch(event.key.code) {
        case sf::Keyboard::Up:
            movePaddleUp();
            break;
        case sf::Keyboard::Down:
            movePaddleDown();
            break;
        default:
            break;
    }
}

void PingPong::mouseEventHandler(const sf::Event& event)
{
    
}

void PingPong::draw(sf::RenderWindow& window)
{
    moveBall();

    window.draw(mBall);
    window.draw(mLeftPaddle);
    window.draw(mRightPaddle);
}

void PingPong::movePaddleUp()
{
    auto position = mRightPaddle.getPosition();
    if(position.y >= 10) {
        mRightPaddle.setPosition(sf::Vector2f(position.x, position.y - 10));
    }
}

void PingPong::movePaddleDown()
{
    auto position = mRightPaddle.getPosition();
    const auto size = mRightPaddle.getSize();
    if((position.y + size.y) <= (Height - 10)) {
        mRightPaddle.setPosition(sf::Vector2f(position.x, position.y + 10));
    }
}

void PingPong::moveBall()
{
    const auto position = mBall.getPosition();

    LOG_DEBUG << "Previous ball position x=" << position.x << " y=" << position.y;
    sf::Vector2f value;
    value.x = position.x + 2 * mBallXDirection;
    value.y = position.y + 2 * mBallYDirection;
    LOG_DEBUG << "Current ball position x=" << value.x << " y=" << value.y;

    if(value.y >= Height || value.y <= 0) {
        mBallYDirection = -mBallYDirection;
    }

    if(value.x >= Width || value.x <= 0) {
        value.x = Width / 2;
        value.y = Height / 2;
    } else {
        checkAndHandleCollision(value);
    }
    mBall.setPosition(value);
}

void PingPong::checkAndHandleCollision(sf::Vector2f& position)
{
    auto rightPosition = mRightPaddle.getPosition();
    auto leftPosition = mLeftPaddle.getPosition();
    if(position.x >= rightPosition.x || position.x <= 10) {
        auto diff = rightPosition.y - position.y;
        const auto size = mRightPaddle.getSize();
        // if(diff < size.y / 2) {
        //     mBallXDirection
        // }
        mBallXDirection = -mBallXDirection;
    }
}
