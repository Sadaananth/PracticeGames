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
    void checkAndHandleCollision(sf::Vector2f& position);

    void movePaddleUp();
    void movePaddleDown();

    sf::RectangleShape mRightPaddle;
    sf::RectangleShape mLeftPaddle;

    sf::CircleShape mBall;
    int mBallXDirection{1};
    int mBallYDirection{1};

    std::thread mBallThread;
};
