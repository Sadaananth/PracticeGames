#include "Board.hpp"

#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

using namespace Sada;

int main()
{
    Board board;
    sf::RenderWindow window(sf::VideoMode(board.width(), board.height()), "Snake");
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Debug);

    while(window.isOpen()) {

        window.clear();
        board.draw(window);
        window.display();
        
        sf::Event event;
        while(window.isOpen() && window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    LOG_DEBUG << "sf::Event::Closed received";
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    LOG_DEBUG << "sf::Event::MouseButtonPressed received";
                    // LOG_DEBUG << "x: " << event.mouseButton.x << " y: " << event.mouseButton.y;
                    break;
                case sf::Event::KeyPressed:
                    LOG_DEBUG << "sf::Event::KeyPressed received";
                    board.mouseButtonPressed(event);
                    break;
                default:
                    break;
            }
        }
    }
    return 0;
}
