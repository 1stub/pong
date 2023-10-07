#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include "paddle.h"

class Ball{
  public:
    Ball();
    void draw(sf::RenderWindow &window);
    void moveBall();
    sf::Vector2f l_paddlePos();
    sf::Vector2f r_paddlePos();
    bool checkIntersectionLeft(const sf::FloatRect& ball, const sf::FloatRect& paddle);
    bool checkIntersectionRight(const sf::FloatRect& ball, const sf::FloatRect& paddle);
  private:
    sf::CircleShape ball;
    sf::Vector2f velocity = sf::Vector2f(4,4);
    bool l_collision = false;
    bool r_collision = false;
    Paddle paddle;
};

#endif
