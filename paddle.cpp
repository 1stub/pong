#include <SFML/Graphics.hpp>
#include <iostream>
#include "paddle.h"

sf::RectangleShape* leftPaddleInstance = nullptr;
sf::RectangleShape* rightPaddleInstance = nullptr;

Paddle::Paddle(){
  l_paddle.setSize(sf::Vector2f(10,100));
  l_paddle.setFillColor(sf::Color::White);
  l_paddle.setPosition(sf::Vector2f(10, 250));
  
  r_paddle.setSize(sf::Vector2f(10,100));
  r_paddle.setFillColor(sf::Color::White);
  r_paddle.setPosition(sf::Vector2f(780, 250));

  Paddle::setPaddles(l_paddle, r_paddle);
}

void Paddle::movePaddles(){
  sf::Vector2f l_paddlePos = l_paddle.getPosition();
  sf::Vector2f r_paddlePos = r_paddle.getPosition();

  float minY = 0;
  float maxY = 600;
  if(l_paddlePos.y < minY){
    l_paddlePos.y = minY;  
  }
  if (l_paddlePos.y + l_paddle.getGlobalBounds().height > maxY) {
    l_paddlePos.y = maxY - l_paddle.getGlobalBounds().height;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::W)) {
    l_paddlePos.y -= newVel.y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)) {
    l_paddlePos.y += newVel.y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
    r_paddlePos.y -= newVel.y;
  }
  if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
    r_paddlePos.y += newVel.y;
  }
  if (r_paddlePos.y < minY) {
    r_paddlePos.y = minY;
  }
  if (r_paddlePos.y + r_paddle.getGlobalBounds().height > maxY) {
    r_paddlePos.y = maxY - r_paddle.getGlobalBounds().height;
  }
  l_paddle.setPosition(l_paddlePos);
  r_paddle.setPosition(r_paddlePos);
}

void Paddle::setPaddles(sf::RectangleShape &leftPaddle, sf::RectangleShape &rightPaddle){
  leftPaddleInstance = &leftPaddle;
  rightPaddleInstance = &rightPaddle;
}

void Paddle::paddleReset(){
  leftPaddleInstance->setPosition(sf::Vector2f(10,250));
  rightPaddleInstance->setPosition(sf::Vector2f(780,250));
} 

sf::FloatRect Paddle::l_paddleBounds() const{
  return l_paddle.getGlobalBounds();
} 

sf::FloatRect Paddle::r_paddleBounds() const{
  return r_paddle.getGlobalBounds(); 
}

void Paddle::drawPaddles(sf::RenderWindow &window){
  window.draw(l_paddle);
  window.draw(r_paddle);
}   
