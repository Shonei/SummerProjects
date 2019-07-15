#pragma once

#include <SFML/Graphics.hpp>

class Option
{
	public:
		Option(sf::Text& t, int w, int h, int m);
		Option();
		sf::Text text;
		int width;
		int hight;
		int mines;
};

