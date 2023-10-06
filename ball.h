#pragma once
#include <SFML/Graphics.hpp>

class Ball{
  public:
    Ball();
    void draw(sf::RenderWindow &window);
    void moveBall();
  private:
    sf::CircleShape ball;
    float ballX;
    float ballY;
    sf::Vector2f velocity = sf::Vector2f(0.1,0.1);
};
