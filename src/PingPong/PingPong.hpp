#pragma once

#include <SFML/Graphics.hpp>

#include <thread>

class PingPong
{
public:
    PingPong();
    ~PingPong() {}

    static const uint32_t Width = 640;
    static const uint32_t Height = 640;

    void keyboardEventHandler(const sf::Event& event);
    void mouseEventHandler(const sf::Event& event);
    void draw(sf::RenderWindow& window);
private:

    void moveBall();
    void checkAndHandleCollision(sf::Vector2f& ballPosition);

    void movePaddleUp();
    void movePaddleDown();

    inline static const uint32_t BallRadius = 15;
    sf::RectangleShape mPaddle;
    sf::Text mText;
    sf::Font mTextFont;

    sf::CircleShape mBall;
    float mBallXDirection{-1};
    float mBallYDirection{-0.2};

    float mBallVelocity{1};
    bool mMoveBall{false};

    uint64_t mPaddleContact{0};
};
