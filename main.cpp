#include <SFML/Graphics.hpp>
#include "ball.h"
#include "paddle.h"
#include "menu.h"

int main()
{
    sf::RenderWindow window(sf::VideoMode(800, 600), "pong", sf::Style::Close);
    float frameLimit = 60.f;
    window.setFramerateLimit(frameLimit);

    Ball ball;
    Paddle paddle;
    Menu menu;
    
    double t = 0.0;
    double dt = 1.0/60.0;

    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        while(!menu.isPlay()){
          menu.run_menu(window);
        }
        while(menu.isPlay()){
          t+=dt;
          window.clear();
          paddle.drawPaddles(window);
          ball.draw(window);
          ball.moveBall(paddle, window, dt);
          paddle.movePaddles();
          window.display();
        }
    }
    return 0;
}
