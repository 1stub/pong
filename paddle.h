#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle{
  public:
    Paddle();
    void drawPaddles(sf::RenderWindow &window);
    void movePaddles();
    void setPaddles(sf::RectangleShape &leftPaddle, sf::RectangleShape &rightPaddle);
    static void paddleReset();
    sf::FloatRect l_paddleBounds() const;
    sf::FloatRect r_paddleBounds() const;

  private:
    sf::RectangleShape l_paddle;
    sf::RectangleShape r_paddle;
    sf::Vector2f newVel = sf::Vector2f(0,5);    
};

#endif
