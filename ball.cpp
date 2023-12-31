#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include "ball.h"

Ball::Ball() : ballBoop(std::make_shared<sf::Sound>()), bounce(std::make_shared<sf::Sound>()){
  ball.setFillColor(sf::Color::White);
  ball.setRadius(10.f);
  float ballX = 400.f;
  float ballY = 300.f;
  sf::Vector2f pos = sf::Vector2f(ballX, ballY);
  ball.setPosition(pos);
  if(!pongBoop.loadFromFile("/home/stub/repos/pong/sounds/pongblipf4.wav"))
  {
    //error
  }
  if(!bounceBoop.loadFromFile("/home/stub/repos/pong/sounds/pongblipg5.wav")){
    //error
  }
  ballBoop->setBuffer(pongBoop);
  bounce->setBuffer(bounceBoop);
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
      Paddle::paddleReset();
      ball.setRadius(0.0);
      if(freezeDuration > 0){
        freezeDuration -= t;
        if(freezeDuration <= 0){
          reposition = true;
          l_playerScore++;
          freezeDuration = 1.0;
          ball.setRadius(10.f);
          newVelocity = sf::Vector2f(4,4);
          this->velocity = sf::Vector2f(4,4);
        }
      }
    }
    if(ballBounds.left < 0){
      Paddle::paddleReset();
      ball.setRadius(0.0);
      if(freezeDuration > 0){
        freezeDuration -= t;
        if(freezeDuration <= 0){
          r_playerScore++;
          reposition = true;
          freezeDuration = 1.0;
          ball.setRadius(10.f);
          newVelocity = sf::Vector2f(4,4);
          this->velocity = sf::Vector2f(4,4);
        }
      }
    }
    if(reposition){
      ball.setPosition(sf::Vector2f(400,300));
      reposition = false;
    }
    if (ballBounds.top < 0 || ballBounds.top + ballBounds.height > 600) {
      bounce->play();  
      newVelocity.y = -newVelocity.y;
    }
    if (ballBounds.intersects(paddle.l_paddleBounds())) {
        ballBoop->play();
        newVelocity.x = std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
        newVelocity = sf::Vector2f(newVelocity.x * 1.1, newVelocity.y * 1.1);          
    }

    if (ballBounds.intersects(paddle.r_paddleBounds())) {
        ballBoop->play();
        newVelocity.x = -std::abs(newVelocity.x);
        newVelocity.y = (newVelocity.y > 0) ? 4 : -4;
        newVelocity = sf::Vector2f(newVelocity.x * 1.1, newVelocity.y * 1.1);          
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


