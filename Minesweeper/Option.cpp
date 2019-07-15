#include "Option.hpp"

Option::Option(sf::Text& t, int w, int h, int m)
{
	text = t;

	width = w;
	hight = h;
	mines = m;
}

Option::Option()
{
	
}