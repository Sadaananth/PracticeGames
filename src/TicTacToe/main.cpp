#include "TicTacToe.hpp"
#include "src/Logger.hpp"

#include <SFML/Graphics.hpp>

using namespace Sada;

int main()
{
    TicTacToe ticTacToe;
    sf::RenderWindow window(sf::VideoMode(ticTacToe.width(), ticTacToe.height()), "TicTacToe");

    Logger::instance().add_sink(Logger::Sink::console, LogLevel::Info);

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            switch(event.type) {
                case sf::Event::Closed:
                    window.close();
                    break;
                case sf::Event::MouseButtonPressed:
                    ticTacToe.mouseButtonPressed(event);
                    break;
                case sf::Event::KeyPressed:
                    ticTacToe.keyButtonPressed(event);
                    break;
                default:
                    break;
            }
        }

        window.clear();
        ticTacToe.draw(window);
        window.display();
    }

    return 0;
}
