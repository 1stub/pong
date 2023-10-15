#include "menu.h"

Menu::Menu(){
  window = new sf::RenderWindow();
  font = new sf::Font();
  
  set_values();
}

Menu::~Menu(){
  delete window;
  delete font;

}

void Menu::set_values(){
  pos = 0;
  pressed = theselect = false;
  font->loadFromFile("/home/stub/repos/pong/fonts/Eight-Bit Madness.ttf");

  pos_mouse = {0,0};
  mouse_coord = {0, 0};

  options = {"Pong", "Play","Quit"};
  texts.resize(3);
  coords = {{590,40},{610,191},{623,457}};
  sizes = {20,24,24};

  for (std::size_t i{}; i < texts.size(); ++i){
   texts[i].setFont(*font); 
   texts[i].setString(options[i]); 
   texts[i].setCharacterSize(sizes[i]);
   texts[i].setOutlineColor(sf::Color::Black);
   texts[i].setPosition(coords[i]);
  }
  texts[1].setOutlineThickness(4);
  pos = 1;
}

void Menu::loop_events(sf::RenderWindow &window){
    pos_mouse = sf::Mouse::getPosition(window);
    mouse_coord = window.mapPixelToCoords(pos_mouse);

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Down) && !pressed){
      if( pos < 4){
        ++pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos - 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Up) && !pressed){
      if( pos > 1){
        --pos;
        pressed = true;
        texts[pos].setOutlineThickness(4);
        texts[pos + 1].setOutlineThickness(0);
        pressed = false;
        theselect = false;
      }
    }

    if(sf::Keyboard::isKeyPressed(sf::Keyboard::Enter) && !theselect){
      theselect = true;
      if( pos == 4){
        window.close();
      }
      std::cout << options[pos] << '\n';
    }
}

void Menu::draw_all(){
  window->clear();
  for(auto t : texts){
   window->draw(t); 
  }
  window->display();
}

void Menu::run_menu(sf::RenderWindow &window){
  while(window.isOpen()){
    loop_events(window);
    draw_all();
  }
}

bool Menu::isPlay(){
  return play;
}
