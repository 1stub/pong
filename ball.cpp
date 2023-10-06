#include <SFML/Graphics.hpp>
#include "ball.h"

Ball::Ball(){
  ball.setFillColor(sf::Color::White);
  ball.setRadius(10.f);
  ballX = 400.f;
  ballY = 300.f;
  ball.setPosition({ballX, ballY});
}

void Ball::draw(sf::RenderWindow &window){
  window.draw(ball);
}

