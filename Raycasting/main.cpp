#include <stdio.h>

#include <SFML/Window.hpp>

#include "Raycasting/Raycasting.hpp"

int main(int argc, char* argv[])
{
    const unsigned int width   = 400;
    const unsigned int height  = 400;

    Raycasting raycasting(width, height);

    sf::RenderWindow window(sf::VideoMode(width, height), "Raycasting");
    window.setFramerateLimit(20);

    while (window.isOpen())
    {
        sf::Event event = {};

        bool lock_click = false;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear(sf::Color::White);

        raycasting.Draw(window);

        window.display();
    }

	return 0;
}