#include <SFML/Graphics.hpp>
#include <SFML/System/String.hpp>
#include <iostream>
#include <sstream>
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

void Ball::moveBall(Paddle paddle, sf::RenderWindow &window) {
    sf::Vector2f currentPosition = ball.getPosition();
    sf::Vector2f newVelocity = velocity;
    sf::FloatRect ballBounds = ball.getGlobalBounds();

    if (ballBounds.left + ballBounds.width > 800) {

      newVelocity.x = -newVelocity.x;
      l_playerScore++;
    }
    if(ballBounds.left < 0){
      newVelocity.x = -newVelocity.x;      
      r_playerScore++;
    }
    if (ballBounds.top < 0 || ballBounds.top + ballBounds.height > 600) {
        newVelocity.y = -newVelocity.y;
    }
    if (ballBounds.intersects(paddle.l_paddleBounds())) {
        newVelocity.x = std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }

    if (ballBounds.intersects(paddle.r_paddleBounds())) {
        newVelocity.x = -std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
    }
    ball.setPosition(currentPosition + newVelocity);
    velocity = newVelocity;

    sf::Font font;
    if (!font.loadFromFile("/home/stub/repos/pong/fonts/Eight-Bit Madness.ttf"))
    {
      //error stuff
    }

    sf::Text l_score;
    l_score.setFont(font);
    l_score.setCharacterSize(36);
    l_score.setFillColor(sf::Color::White);
    l_score.setPosition(100.f, 100.f);
    std::stringstream ss;
    ss << l_playerScore;
    l_score.setString(ss.str());

    window.draw(l_score);
}
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */


