#include "OptionsMenu.hpp"

OptionsMenu::OptionsMenu()
{
	if(!font.loadFromFile("FeFCrm2.ttf")) 
	{
		// error
	}

	input.setFont(font);

	activeIndex = -1;

	returnValue.x = -1;
	returnValue.y = -1;
	returnValue.z = -1;

	option.resize(3);

	sf::Text presetOption;
	presetOption.setFont(font);
	presetOption.setCharacterSize(24);
	presetOption.setColor(sf::Color::Red);
	presetOption.setStyle(sf::Text::Bold);

	presetOption.setString("10 x 10");
	option[0] = Option(presetOption, 10, 10, 10);

	presetOption.setString("16 x 16");
	option[1] = Option(presetOption, 16, 16, 16);

	presetOption.setString("25 x 25");
	option[2] = Option(presetOption, 25, 25, 25);
}

void OptionsMenu::setPosition(int x, int y)
{
	option[0].text.setPosition(x / 4, 0);
	option[1].text.setPosition(x / 4, y / 4);
	option[2].text.setPosition(x / 4, y / 2);

	input.setPosition(x, y);
}

void OptionsMenu::draw(sf::RenderWindow& window)
{	
	if(activeIndex >= 0 && activeIndex < 3)
	{
		option[activeIndex].text.setColor(sf::Color::Green);
	}

	window.draw(option[0].text);
	window.draw(option[1].text);
	window.draw(option[2].text);
	input.draw(window);
}

void OptionsMenu::handleEvent(const sf::Event& event)
{
	if (event.type == sf::Event::MouseButtonPressed)
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
				else 
				{
					if(activeIndex >= 0 && activeIndex <= 2)
					{
						option[activeIndex].text.setColor(sf::Color::Red);
					}
					else if(activeIndex == 3)
					{
						input.setColor(sf::Color::Red);
					}
					activeIndex = i;
				} 
			}
    	}

    	if(input.isIctivated(event.mouseButton.x, event.mouseButton.y))
    	{
    		if(activeIndex == 3)
    		{
    			input.setColor(sf::Color::Red);

    			activeIndex = -1;
    		}
    		else if(activeIndex >= 0 && activeIndex <= 2)
    		{
    			input.setColor(sf::Color::Green);
    			option[activeIndex].text.setColor(sf::Color::Red);
    			activeIndex = 3;
    		}
    		else
    		{
    			input.setColor(sf::Color::Green);
    			activeIndex = 3;
    		}
    	}

	}
	if(activeIndex == 3)
	{
		input.handleEvent(event);
	}

}

sf::Vector3f OptionsMenu::getSettings()
{
	if(activeIndex == 3)
	{
		returnValue = input.getVal();

		activeIndex = -1;
		input.setColor(sf::Color::Red);
	}
	else if(activeIndex >= 0)
	{
		returnValue.x = option[activeIndex].width;
		returnValue.y = option[activeIndex].hight;
		returnValue.z = option[activeIndex].mines;
	
		option[activeIndex].text.setColor(sf::Color::Red);
		activeIndex = -1;
	}

	return returnValue;
}