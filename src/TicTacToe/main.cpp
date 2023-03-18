#include "TicTacToe.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    TicTacToe ticTacToe;
    sf::RenderWindow window(sf::VideoMode(ticTacToe.width(), ticTacToe.height()), "SFML works!");

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