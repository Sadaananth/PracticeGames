#include "TicTacToe.hpp"

#include <SFML/Graphics.hpp>

int main()
{
    TicTacToe ticTacToe;
    sf::RenderWindow window(sf::VideoMode(640, 480), "SFML works!");

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ticTacToe.draw(window);
        window.display();
    }

    return 0;
}
