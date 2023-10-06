#include <SFML/Graphics.hpp>
#include <SFML/Graphics/RectangleShape.hpp>

class Paddle{
  public:
    Paddle();
    void drawPaddles(sf::RenderWindow &window);
  
  private:
    sf::RectangleShape l_paddle;
    sf::RectangleShape r_paddle;
    float xPos;
    float yPos; 
};
