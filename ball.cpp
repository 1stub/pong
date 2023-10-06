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

void Ball::moveBall(){
  if(ball.getPosition().x > 800){
    velocity = sf::Vector2f(-0.1,-0.1);
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().x < 0){
    velocity = sf::Vector2f(0.1,0.1);
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().y < 0){
    velocity = sf::Vector2f(0.1, 0.1);
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().y > 600){
    velocity = sf::Vector2f(0.1, -0.1);
    ball.setPosition(ball.getPosition() + velocity);
  }
  else{
    ball.setPosition(ball.getPosition() + velocity);
  }
}

