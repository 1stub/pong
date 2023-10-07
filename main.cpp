#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "pong", sf::Style::Close);
    float frameLimit = 60.f;
    window.setFramerateLimit(frameLimit);

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
        ball.moveBall();
        paddle.drawPaddles(window);
        paddle.movePaddles();
        window.display();
    }

    return 0;
}
