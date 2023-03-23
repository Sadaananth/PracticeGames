#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

using namespace Sada;

int main()
{
    sf::RenderWindow window(sf::VideoMode(400, 400), "Snake");
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Info);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    LOG_DEBUG << "sf::Event::Closed received";
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    LOG_DEBUG << "sf::Event::MouseButtonPressed received";
                    break;
                case sf::Event::KeyPressed:
                    LOG_DEBUG << "sf::Event::KeyPressed received";
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
        window.display();
    }
    return 0;
}
