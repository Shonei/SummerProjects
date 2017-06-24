#include "OptionsMenu.hpp"

OptionsMenu::OptionsMenu()
{
	if(!font.loadFromFile("FeFCrm2.ttf")) 
	{
		// error
	}

	activeIndex = -1;

	returnValue.x = -1;
	returnValue.y = -1;
	returnValue.z = -1;

	sf::Text option1;
	option1.setFont(font);
	option1.setCharacterSize(24);
	option1.setColor(sf::Color::Red);
	option1.setStyle(sf::Text::Bold);

	option1.setString("16 x 16");
	Option one(option1, 16, 16, 10);

	option1.setString("32 x 32");
	Option two(option1, 32, 32, 15);

	option1.setString("40 x 40");
	Option tree(option1, 40, 40, 20);

	option.resize(3);

	option[0] = one;
	option[1] = two;
	option[2] = tree;
}

void OptionsMenu::draw(sf::RenderWindow& window)
{	
	if(activeIndex >= 0)
	{
		option[activeIndex].text.setColor(sf::Color::Green);
	}

	int x = window.getSize().x;
	int y = window.getSize().y;

	option[0].text.setPosition(x / 4, 0);
	option[1].text.setPosition(x / 4, y / 4);
	option[2].text.setPosition(x / 4, y / 2);

	window.draw(option[0].text);
	window.draw(option[1].text);
	window.draw(option[2].text);
}

void OptionsMenu::handleEvent(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{

	}
	else if (event.type == sf::Event::MouseButtonPressed)
	{
		for (unsigned int i = 0; i < option.size(); i++)
    	{
    		sf::FloatRect temp = option[i].text.getGlobalBounds();

    		if(temp.contains(sf::Vector2f(event.mouseButton.x, event.mouseButton.y)))
			{
				if(activeIndex == (int)i)
				{
					option[i].text.setColor(sf::Color::Red);
					activeIndex = -1;
				}
				else if(activeIndex != (int)i) 
				{
					// option[i].text.setColor(sf::Color::Red);
					activeIndex = i;
				} 
			}
    	}
	}
}

OptionsMenu::~OptionsMenu()
{

}

sf::Vector3f OptionsMenu::getSettings()
{
	if(activeIndex >= 0)
	{
		returnValue.x = option[activeIndex].width;
		returnValue.y = option[activeIndex].hight;
		returnValue.z = option[activeIndex].mines;
	}

	return returnValue;
}