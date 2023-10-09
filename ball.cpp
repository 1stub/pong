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

void Ball::moveBall(Paddle paddle, sf::RenderWindow &window, double &dt) {
    double t = 1.0/60.0;
    sf::Vector2f newVelocity = velocity;
    sf::FloatRect ballBounds = ball.getGlobalBounds();
    bool reposition = false;

    if (ballBounds.left + ballBounds.width > 800) {
      ball.setRadius(0.0);
      if(freezeDuration > 0){
        freezeDuration -= t;
        if(freezeDuration <= 0){
          l_playerScore++;
          reposition = true;
          newVelocity.x = -newVelocity.x;
          freezeDuration = 1.0;
          ball.setRadius(10.f);
        }
      }
    }
    if(ballBounds.left < 0){
      ball.setRadius(0.0);
      if(freezeDuration > 0){
        freezeDuration -= t;
        if(freezeDuration <= 0){
          r_playerScore++;
          reposition = true;
          newVelocity.x = -newVelocity.x;
          freezeDuration = 1.0;
          ball.setRadius(10.f);
        }
      }
    }
    if(reposition){
      ball.setPosition(sf::Vector2f(400,300));
      reposition = false;
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

    ball.setPosition(ball.getPosition() + newVelocity);
    velocity = newVelocity;

    sf::Font font;
    if (!font.loadFromFile("/home/stub/repos/pong/fonts/Eight-Bit Madness.ttf"))
    {
      //error stuff
    }

    // Move to do different function
    sf::Text l_score;
    l_score.setFont(font);
    l_score.setCharacterSize(64);
    l_score.setFillColor(sf::Color::White);
    l_score.setPosition(100.f, 100.f);
    std::stringstream ss;
    ss << l_playerScore;
    l_score.setString(ss.str());

    sf::Text r_score;
    r_score.setFont(font);
    r_score.setCharacterSize(64);
    r_score.setFillColor(sf::Color::White);
    r_score.setPosition(660.f, 100.f);
    std::stringstream sss;
    sss << r_playerScore;
    r_score.setString(sss.str());
  
    window.draw(l_score);
    window.draw(r_score);
}
  /*
    sf::Vector2f objectPosition = objectSprite.getPosition();
    float x = objectPosition.x;
    float y = objectPosition.y;
    std::cout << "Object X: " << x << ", Y: " << y << std::endl;
   */


