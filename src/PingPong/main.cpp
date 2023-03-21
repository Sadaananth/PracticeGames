#include "PingPong.hpp"
#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

using namespace Sada;

int main()
{
    PingPong pingPong;
    sf::RenderWindow window(sf::VideoMode(PingPong::Width, PingPong::Height), "Ping Pong");
    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Debug);

    while(window.isOpen()) {
        sf::Event event;

        while(window.pollEvent(event)) {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    pingPong.mouseEventHandler(event);
                    break;
                case sf::Event::KeyPressed:
                    pingPong.keyboardEventHandler(event);
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
