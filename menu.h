#pragma once

#define MAX_ITEMS 2

#include <SFML/Graphics.hpp>
#include <iostream>

class Menu {
  public:
    Menu();
    ~Menu();
    void drawMenu(sf::RenderWindow &window);
    void MoveUp();
    void MoveDown();
    bool isPlay();

  private:
    sf::Text menu[MAX_ITEMS];
    sf::Text title;
    sf::Font font;
    float width = 800;
    float height = 600;
    int selectedItemIndex;
    bool play = false;
}; 
