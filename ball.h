#ifndef BALL_H
#define BALL_H

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <cwchar>
#include <memory>
#include "paddle.h"

class Ball{
  public:
    Ball();
    void draw(sf::RenderWindow &window);
    void moveBall(Paddle paddle, sf::RenderWindow &window, double &dt);
    sf::Vector2f l_paddlePos();
    sf::Vector2f r_paddlePos();
    bool checkIntersectionLeft(const sf::FloatRect& ball, const sf::FloatRect& paddle);
    bool checkIntersectionRight(const sf::FloatRect& ball, const sf::FloatRect& paddle);
  private:
    sf::CircleShape ball;
    sf::Vector2f velocity = sf::Vector2f(4,4);
    bool l_collision = false;
    bool r_collision = false;
    int l_playerScore = 0;
    int r_playerScore = 0;
    bool delayFinished;
    double freezeDuration = 1.0;
    sf::Clock delayClock;
    sf::SoundBuffer pongBoop;
    std::shared_ptr<sf::Sound> ballBoop;
    bool canPlaySound = true;
};

#endif
