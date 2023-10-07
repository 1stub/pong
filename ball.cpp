#include <SFML/Graphics.hpp>
#include <SFML/Graphics/Rect.hpp>
#include <iostream>
#include "ball.h"

Ball::Ball(){
  ball.setFillColor(sf::Color::White);
  ball.setRadius(10.f);
  float ballX = 400.f;
  float ballY = 300.f;
  sf::Vector2f pos = sf::Vector2f(ballX, ballY);
  ball.setPosition(pos);
  
  paddle = Paddle();
}

void Ball::draw(sf::RenderWindow &window){
  window.draw(ball);
}

void Ball::moveBall(){
    sf::Vector2f currentPosition = ball.getPosition();
    sf::Vector2f newVelocity;

    if (currentPosition.x > 800) {
      newVelocity.x = -4;
      newVelocity.y = (velocity.y > 0) ? 4 : -4;
    }
    else if (currentPosition.x < 0) {
      newVelocity.x = 4;
      newVelocity.y = (velocity.y > 0) ? 4 : -4;
    }
    else if (currentPosition.y < 0) {
      newVelocity.x = (velocity.x > 0) ? 4 : -4;
      newVelocity.y = 4;
    }
    else if (currentPosition.y > 600) {
      newVelocity.x = (velocity.x > 0) ? 4 : -4;
      newVelocity.y = -4;
    }
    else if(l_collision){
      newVelocity.x = 4;
      newVelocity.y = (velocity.y > 0) ? 4 : -4;
      l_collision = false;
    }
    else if(r_collision){
      newVelocity.x = 4;
      newVelocity.y = (velocity.y > 0) ? 4 : -4;
      r_collision = false;
    }

    else {
      newVelocity = velocity;
    }

    ball.setPosition(currentPosition + newVelocity);
    velocity = newVelocity;
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */
}


bool Ball::checkIntersection(const sf::FloatRect& ball, const sf::FloatRect& paddle){
  return ball.left < paddle.left + paddle.width &&
        ball.left + ball.width > paddle.left &&
        ball.top < paddle.top + paddle.height &&
        ball.top + ball.height > paddle.top;
}

void Ball::checkCollisions(){
  sf::FloatRect ballBounds = ball.getGlobalBounds();
  sf::FloatRect l_paddleBounds = paddle.l_paddleBounds();
  sf::FloatRect r_paddleBounds = paddle.r_paddleBounds();
  
  if(checkIntersection(ballBounds, l_paddleBounds)){
    this->velocity = sf::Vector2f(4,velocity.y);
  }
  if(checkIntersection(ballBounds, r_paddleBounds)){
    this->velocity = sf::Vector2f(-4,velocity.y);
  }
}








