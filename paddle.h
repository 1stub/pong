#ifndef PADDLE_H
#define PADDLE_H

#include <SFML/Graphics.hpp>

class Paddle{
  public:
    Paddle();
    void drawPaddles(sf::RenderWindow &window);
    void movePaddles();
    sf::FloatRect l_paddleBounds() const;
    sf::FloatRect r_paddleBounds() const;
  private:
    sf::RectangleShape l_paddle;
    sf::RectangleShape r_paddle;
};

#endif
