#include "OptionsMenu.hpp"

OptionsMenu::OptionsMenu()
{
	if(!font.loadFromFile("FeFCrm2.ttf")) 
	{
		// error
	}

	input1.setFont(font);
	input2.setFont(font);
	input3.setFont(font);

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

	input1.setPosition(0, (y / 4) * 3);
	input2.setPosition(x / 3, (y / 4) * 3);
	input3.setPosition((x / 3) * 2, (y / 4) * 3);
}

void OptionsMenu::draw(sf::RenderWindow& window)
{	
	if(activeIndex >= 0)
	{
		option[activeIndex].text.setColor(sf::Color::Green);
	}

	window.draw(option[0].text);
	window.draw(option[1].text);
	window.draw(option[2].text);
	input1.draw(window);
}

void OptionsMenu::handleEvent(sf::Event event)
{
	if(event.type == sf::Event::KeyPressed)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Numpad1:
			case sf::Keyboard::Num1:
				input1.add('1');
				break;

			case sf::Keyboard::Numpad2:
			case sf::Keyboard::Num2:
				input1.add('2');
				break;

			case sf::Keyboard::Numpad3:
			case sf::Keyboard::Num3:
				input1.add('3');
				break;

			case sf::Keyboard::Numpad4:
			case sf::Keyboard::Num4:
				input1.add('4');
				break;

			case sf::Keyboard::Numpad5:
			case sf::Keyboard::Num5:
				input1.add('5');
				break;

			case sf::Keyboard::Numpad6:
			case sf::Keyboard::Num6:
				input1.add('6');
				break;

			case sf::Keyboard::Numpad7:
			case sf::Keyboard::Num7:
				input1.add('7');
				break;

			case sf::Keyboard::Numpad8:
			case sf::Keyboard::Num8:
				input1.add('8');
				break;

			case sf::Keyboard::Numpad9:
			case sf::Keyboard::Num9:
				input1.add('9');
				break;

			case sf::Keyboard::BackSpace:
				input1.remove();
				break;

			default:
				break;
		}
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
					if(activeIndex >= 0)
					{
						option[activeIndex].text.setColor(sf::Color::Red);
					}
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
	
		option[activeIndex].text.setColor(sf::Color::Red);
		activeIndex = -1;
	}

	return returnValue;
}