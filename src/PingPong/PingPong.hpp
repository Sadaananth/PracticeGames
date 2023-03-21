#pragma once

#include <SFML/Graphics.hpp>

class PingPong
{
public:
    PingPong() {}
    ~PingPong() {}

    static const uint32_t Width = 640;
    static const uint32_t Height = 480;

    void keyboardEventHandler(const sf::Event& event);
    void mouseEventHandler(const sf::Event& event);
    void draw(sf::RenderWindow& window);
private:


};
