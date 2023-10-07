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

    sf::Clock clock;
    float timeStep = 1.0f / frameLimit;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }

        float elapsedTime = clock.restart().asSeconds();

        while (elapsedTime > 0)
        {
            float deltaTime = std::min(elapsedTime, timeStep);
            ball.moveBall();
            paddle.movePaddles();

            ball.checkCollisions();
            elapsedTime -= deltaTime;
        }
        window.clear();
        paddle.drawPaddles(window);
        ball.draw(window);

        window.display();
    }

    return 0;
}
