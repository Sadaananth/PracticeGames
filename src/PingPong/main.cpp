#include "PingPong.hpp"
#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

using namespace Sada;

int main()
{
    PingPong pingPong;
    sf::RenderWindow window(sf::VideoMode(PingPong::Width, PingPong::Height), "Ping Pong");
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
                    pingPong.mouseEventHandler(event);
                    break;
                case sf::Event::KeyPressed:
                    LOG_DEBUG << "sf::Event::KeyPressed received";
                    pingPong.keyboardEventHandler(event);
                    break;
                default:
                    break;
            }
        }
        
        window.clear();
        pingPong.draw(window);
        window.display();
        // std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
    return 0;
}
