#include "InputBox.hpp"

InputBox::InputBox(std::string s)
{
	text.setCharacterSize(24);
	text.setColor(sf::Color::Blue);
	text.setStyle(sf::Text::Bold);

	val = s;

	text.setString(val);
}

void InputBox::setFont(const sf::Font& f)
{
	text.setFont(f);
}

void InputBox::setPosition(int x, int y)
{
	text.setPosition(x, y);
}

void InputBox::add(char c)
{
	if(val.size() < 2)
	{
		val.push_back(c);
		text.setString(val);
	}
}

void InputBox::remove()
{
	if(val.size() != 0)
	{
		val.pop_back();
		text.setString(val);
	}
}

int InputBox::getVal() const
{
	return atoi(val.c_str());
}

void InputBox::draw(sf::RenderWindow& window)
{
	window.draw(text);
}