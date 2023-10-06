#pragma once
#include <SFML/Graphics.hpp>

class Ball{
  public:
    Ball();
    void draw(sf::RenderWindow &window);
    void moveBall();
  private:
    sf::CircleShape ball;
    sf::Vector2f velocity = sf::Vector2f(0.1,0.1);
};
