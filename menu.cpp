#include "menu.h"

Menu::Menu(){
	if (!font.loadFromFile("/home/stub/repos/pong/fonts/Eight-Bit Madness.ttf"))
	{
		//Error handle
	}
	title.setFont(font);
	title.setStyle(sf::Text::Bold);
	title.setCharacterSize(40);
	title.setFillColor(sf::Color::Blue);
	title.setPosition(sf::Vector2f(width / 4, height / 16));
	title.setString("Pong");

	menu[0].setFont(font);
	menu[0].setFillColor(sf::Color::Red);
	menu[0].setString("Play");
	menu[0].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 1));

	menu[1].setFont(font);
	menu[1].setFillColor(sf::Color::White);
	menu[1].setString("Exit");
	menu[1].setPosition(sf::Vector2f(width / 2, height / (MAX_ITEMS + 1) * 3));

	selectedItemIndex = 0;
}

Menu::~Menu()
{
}

void Menu::drawMenu(sf::RenderWindow& window)
{
	window.draw(title);
	for (int i = 0; i < MAX_ITEMS; i++) {
		window.draw(menu[i]);
	}
}

void Menu::MoveUp()
{
	if (selectedItemIndex - 1 >= 0)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex--;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

void Menu::MoveDown()
{
	if (selectedItemIndex + 1 < MAX_ITEMS)
	{
		menu[selectedItemIndex].setFillColor(sf::Color::White);
		selectedItemIndex++;
		menu[selectedItemIndex].setFillColor(sf::Color::Red);
	}
}

bool Menu::isPlay(){
  return play;
}
