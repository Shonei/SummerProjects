#include "OptionsMenu.hpp"
#include "iostream"
#include "string"

OptionsMenu::OptionsMenu()
{
	sf::Font font;
	font.loadFromFile("FeFCrm2.ttf");
	
	options.resize(3);
	
	sf::Text text("hello", font);
	text.setCharacterSize(30);
	text.setStyle(sf::Text::Bold);
	text.setColor(sf::Color::Red);

	options[0] = SingleOption(text, sf::Vector3i(20, 20, 20));
}

void OptionsMenu::draw(sf::RenderWindow& window) const
{
	window.draw(options[0].text);
	
}

OptionsMenu::~OptionsMenu()
{

}