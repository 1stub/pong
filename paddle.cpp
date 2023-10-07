#include <SFML/Graphics.hpp>
#include <SFML/Window/Keyboard.hpp>
#include "paddle.h"

Paddle::Paddle(){
  l_paddle.setSize(sf::Vector2f(10,100));
  l_paddle.setFillColor(sf::Color::White);
  l_paddle.setPosition(sf::Vector2f(10, 250));
  
  r_paddle.setSize(sf::Vector2f(10,100));
  r_paddle.setFillColor(sf::Color::White);
  r_paddle.setPosition(sf::Vector2f(780, 250));

}

void Paddle::movePaddles(){
  sf::Vector2f newVel = sf::Vector2f(0,4);
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up)){
    r_paddle.setPosition(r_paddle.getPosition() - newVel);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down)){
    r_paddle.setPosition(r_paddle.getPosition() + newVel);
  }

  if(sf::Keyboard::isKeyPressed(sf::Keyboard::W)){
    l_paddle.setPosition(l_paddle.getPosition() - newVel);
  }
  if(sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
    l_paddle.setPosition(l_paddle.getPosition() + newVel);
  }

}

void Paddle::drawPaddles(sf::RenderWindow &window){
  window.draw(l_paddle);
  window.draw(r_paddle);
}     
