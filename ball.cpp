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

void Ball::moveBall(Paddle paddle) {
    sf::Vector2f currentPosition = ball.getPosition();
    sf::Vector2f newVelocity = velocity;

    if (currentPosition.x > 800 || currentPosition.x < 0) {
        newVelocity.x = -newVelocity.x;
    }
    if (currentPosition.y < 0 || currentPosition.y > 600) {
        newVelocity.y = -newVelocity.y;
    }
    if (ball.getGlobalBounds().intersects(paddle.l_paddleBounds())) {
        newVelocity.x = std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }

    if (ball.getGlobalBounds().intersects(paddle.r_paddleBounds())) {
        newVelocity.x = -std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }
    ball.setPosition(currentPosition + newVelocity);
    velocity = newVelocity;
    
}
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */


