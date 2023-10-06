#pragma once
#include <SFML/Graphics.hpp>

class Ball{
  public:
    Ball();
    void draw(sf::RenderWindow &window);
  private:
    sf::CircleShape ball;
    float ballX;
    float ballY;
};
