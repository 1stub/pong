#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "SFML works!", sf::Style::Close);

    Ball ball;
    Paddle paddle;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        window.clear();
        ball.draw(window);
        paddle.drawPaddles(window);
        window.display();
    }

    return 0;
}
