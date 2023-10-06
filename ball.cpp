#include <SFML/Graphics.hpp>
#include <iostream>
#include "ball.h"

Ball::Ball(){
  ball.setFillColor(sf::Color::White);
  ball.setRadius(10.f);
  float ballX = 400.f;
  float ballY = 300.f;
  sf::Vector2f pos = sf::Vector2f(ballX, ballY);
  ball.setPosition(pos);
}

void Ball::draw(sf::RenderWindow &window){
  window.draw(ball);
}

void Ball::moveBall(){
  if(ball.getPosition().x > 800){
    if(velocity.y > 0){
      velocity = sf::Vector2f(-0.1, 0.1);
    }
    else{ 
      velocity = sf::Vector2f(-0.1, -0.1);
    }
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().x < 0){
    if(velocity.y > 0){
      velocity = sf::Vector2f(0.1, 0.1);
    }
    else{ 
      velocity = sf::Vector2f(0.1, -0.1);
    }
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().y < 0){
    if(velocity.x > 0){
      velocity = sf::Vector2f(0.1, 0.1);
    }
    else{ 
      velocity = sf::Vector2f(-0.1, 0.1);
    }
    ball.setPosition(ball.getPosition() + velocity);
  }
  if(ball.getPosition().y > 600){
    if(velocity.x > 0){
      velocity = sf::Vector2f(0.1, -0.1);
    }
    else{ 
      velocity = sf::Vector2f(-0.1, -0.1);
    }
    ball.setPosition(ball.getPosition() + velocity);
  }
  else{
    ball.setPosition(ball.getPosition() + velocity);
  }
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */
}

