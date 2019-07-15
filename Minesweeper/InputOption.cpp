#include "InputOption.hpp"

InputOption::InputOption()
{
	inputs.resize(3);

	inputs[0] = InputBox("");
	inputs[1] = InputBox("");
	inputs[2] = InputBox("");

	activeIndex = 0;

	rectangle.setSize(sf::Vector2f(100, 50));
	rectangle.setOutlineColor(sf::Color::Red);
	rectangle.setFillColor(sf::Color::Black);
	rectangle.setOutlineThickness(3);
}

void InputOption::setFont(const sf::Font& f)
{
	inputs[0].setFont(f);
	inputs[1].setFont(f);
	inputs[2].setFont(f);
}

void InputOption::setPosition(const int x, const int y)
{
	inputs[0].setPosition(0, (y / 4) * 3);
	inputs[1].setPosition(x / 3, (y / 4) * 3);
	inputs[2].setPosition((x / 3) * 2, (y / 4) * 3);

	rectangle.setSize(sf::Vector2f(x - 10, (y / 4) - 10));
	rectangle.setPosition(5, (y / 4) * 3 - 5);
}	

void InputOption::draw(sf::RenderWindow& window)
{
	window.draw(rectangle);

	inputs[0].draw(window);
	inputs[1].draw(window);
	inputs[2].draw(window);
}

sf::Vector3f InputOption::getVal()
{
	sf::Vector3f v;

	v.x = inputs[0].getVal();
	v.y = inputs[1].getVal();
	v.z = inputs[2].getVal();

	inputs[0].reset();
	inputs[1].reset();
	inputs[2].reset();

	activeIndex = 0;

	return v;
}

void InputOption::updateActiveIndex(const int i)
{
	activeIndex = i;
}

void InputOption::handleEvent(const sf::Event& event)
{
	if(event.type == sf::Event::KeyPressed &&
		activeIndex != -1)
	{
		switch (event.key.code)
		{
			case sf::Keyboard::Numpad0:
			case sf::Keyboard::Num0:
				inputs[activeIndex].add('0');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad1:
			case sf::Keyboard::Num1:
				inputs[activeIndex].add('1');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad2:
			case sf::Keyboard::Num2:
				inputs[activeIndex].add('2');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad3:
			case sf::Keyboard::Num3:
				inputs[activeIndex].add('3');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad4:
			case sf::Keyboard::Num4:
				inputs[activeIndex].add('4');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad5:
			case sf::Keyboard::Num5:
				inputs[activeIndex].add('5');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad6:
			case sf::Keyboard::Num6:
				inputs[activeIndex].add('6');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad7:
			case sf::Keyboard::Num7:
				inputs[activeIndex].add('7');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad8:
			case sf::Keyboard::Num8:
				inputs[activeIndex].add('8');
				checkActiveIndex();
				break;

			case sf::Keyboard::Numpad9:
			case sf::Keyboard::Num9:
				inputs[activeIndex].add('9');
				checkActiveIndex();
				break;

			case sf::Keyboard::BackSpace:
				inputs[activeIndex].remove();
				
				if(inputs[activeIndex].size() == 0 &&
					activeIndex > 0)
				{
					activeIndex = activeIndex - 1;
				}

				break;

			default:
				break;
		}
	}
}

bool InputOption::isIctivated(const int x, const int y)
{
	if(rectangle.getGlobalBounds().contains(sf::Vector2f(x, y)))
	{
		return true;
	}

	return false;
}

void InputOption::checkActiveIndex()
{
	if(inputs[activeIndex].size() == 2 &&
	activeIndex < 2)
	{
		activeIndex = activeIndex + 1;
	}
}

void InputOption::setColor(const sf::Color& c)
{
		rectangle.setOutlineColor(c);
}