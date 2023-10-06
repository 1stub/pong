#include <SFML/Graphics.hpp>
#include "paddle.h"

Paddle::Paddle(){
  l_paddle.setSize(sf::Vector2f(10,100));
  l_paddle.setFillColor(sf::Color::White);
  l_paddle.setPosition(sf::Vector2f(10, 200));
  
  r_paddle.setSize(sf::Vector2f(10,100));
  r_paddle.setFillColor(sf::Color::White);
  r_paddle.setPosition(sf::Vector2f(780, 200));

}

void Paddle::drawPaddles(sf::RenderWindow &window){
  window.draw(l_paddle);
  window.draw(r_paddle);
}
