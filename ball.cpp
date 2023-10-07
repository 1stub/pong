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

void Ball::moveBall() {
    sf::Vector2f currentPosition = ball.getPosition();
    sf::Vector2f newVelocity = velocity; // Start with the current velocity.

    // Check if the ball hits the screen edges and adjust the velocity accordingly.
    if (currentPosition.x > 800 || currentPosition.x < 0) {
        newVelocity.x = -newVelocity.x;
    }
    if (currentPosition.y < 0 || currentPosition.y > 600) {
        newVelocity.y = -newVelocity.y;
    }

    // Check for collisions with paddles (left and right).
    sf::FloatRect ballBounds = ball.getGlobalBounds();
    sf::FloatRect l_paddleBounds = paddle.l_paddleBounds();
    sf::FloatRect r_paddleBounds = paddle.r_paddleBounds();

    if (checkIntersectionLeft(ballBounds, l_paddleBounds)) {
        // Handle collision with left paddle.
        // Adjust the ball's horizontal velocity and ensure it moves away from the paddle.
        newVelocity.x = std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }

    if (checkIntersectionRight(ballBounds, r_paddleBounds)) {
        // Handle collision with right paddle.
        // Adjust the ball's horizontal velocity and ensure it moves away from the paddle.
        newVelocity.x = -std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }

    // Update the ball's position using the adjusted velocity.
    ball.setPosition(currentPosition + newVelocity);

    // Update the ball's velocity.
    velocity = newVelocity;
}
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */

bool Ball::checkIntersectionLeft(const sf::FloatRect& ball, const sf::FloatRect& paddle){
  return ball.left < paddle.left + paddle.width &&
        ball.left + ball.width > paddle.left &&
        ball.top < paddle.top + paddle.height &&
        ball.top + ball.height > paddle.top;
}

bool Ball::checkIntersectionRight(const sf::FloatRect& ball, const sf::FloatRect& paddle){
  return ball.left + ball.width < paddle.left + paddle.width &&
        ball.left > paddle.left &&
        ball.top < paddle.top + paddle.height &&
        ball.top + ball.height > paddle.top;
}









