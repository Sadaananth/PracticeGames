#include "src/Logger.hpp"

#include "PingPong.hpp"

#include <cmath>

using namespace Sada;

PingPong::PingPong()
{
    mBall.setRadius(BallRadius);
    mBall.setFillColor(sf::Color::White);
    mBall.setPosition(sf::Vector2f(Width / 2, Height / 2));
    
    mPaddle.setSize(sf::Vector2f(10, Height / 4));
    mPaddle.setFillColor(sf::Color::White);
    mPaddle.setPosition(sf::Vector2f(Width - 10, 0));

    if(!mTextFont.loadFromFile("resources/AntiCorona.ttf")) {
        throw std::runtime_error("Failed to load font");
    }
    mText.setFont(mTextFont);
    mText.setCharacterSize(50);
    mText.setPosition(sf::Vector2f(50, 50));
    mText.setFillColor(sf::Color::Green);
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
    if(mMoveBall) {
        moveBall();
    }

    window.draw(mBall);
    window.draw(mPaddle);

    mText.setString(std::to_string(mPaddleContact));
    window.draw(mText);
}

void PingPong::movePaddleUp()
{
    mMoveBall = true;
    auto position = mPaddle.getPosition();
    if(position.y >= 10) {
        mPaddle.setPosition(sf::Vector2f(position.x, position.y - 30));
    }
}

void PingPong::movePaddleDown()
{
    mMoveBall = true;
    auto position = mPaddle.getPosition();
    const auto size = mPaddle.getSize();
    if((position.y + size.y) <= (Height - 10)) {
        mPaddle.setPosition(sf::Vector2f(position.x, position.y + 30));
    }
}

void PingPong::moveBall()
{
    sf::Vector2f value = mBall.getPosition();

    if(value.y + BallRadius >= Height || value.y - BallRadius <= 0) {
        mBallYDirection = -mBallYDirection;
        LOG_INFO << "Ball collided with the horizontal wall";
    }

    if(value.x - BallRadius <= 0) {
        mBallXDirection = -mBallXDirection;
        LOG_INFO << "Ball collided with the left wall";
    } else if(value.x + BallRadius >= Width) {
        value.x = Width / 2;
        value.y = Height / 2;
        mPaddleContact = 0;
        mMoveBall = false;
        LOG_INFO << "Lost Game";
    } else {
        checkAndHandleCollision(value);
    }

    LOG_DEBUG << "Old Value: " << value.x << ", " << value.y;
    value.y = value.y + mBallVelocity * mBallYDirection;
    value.x = value.x + mBallVelocity * mBallXDirection;
    LOG_DEBUG << "New Value: " << value.x << ", " << value.y;
    mBall.setPosition(value);
}

void PingPong::checkAndHandleCollision(sf::Vector2f& ballPosition)
{
    auto paddlePosition = mPaddle.getPosition();
    auto diff = ballPosition.y - paddlePosition.y;
    const auto paddleSize = mPaddle.getSize();
    if(ballPosition.x + BallRadius >= paddlePosition.x && diff <= paddleSize.y && diff >= 0) {

        LOG_INFO << "Ball contacted with Paddle";

        diff = diff - paddleSize.y / 2;
        diff = diff / (paddleSize.y / 2);

        auto value = sin(diff * 90 * 3.14 / 180 );

        LOG_INFO << "Before Ball velocity: " << mBallVelocity;
        LOG_INFO << "Sin value " << value;
        mBallVelocity = mBallVelocity + 0.2 * value;
        LOG_INFO << "After Ball velocity: " << mBallVelocity;

        LOG_INFO << "Before BallXdirection: " << mBallXDirection;
        mBallXDirection = -(mBallXDirection + fabs(0.1 * value));
        LOG_INFO << "After BallXdirection: " << mBallXDirection;

        mPaddleContact++;
    }
}
