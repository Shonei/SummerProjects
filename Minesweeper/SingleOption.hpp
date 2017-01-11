#pragma once

#include <SFML/Graphics.hpp>

class SingleOption
{
public:
	SingleOption() { }
	SingleOption(sf::Text t, sf::Vector3i v) : text(t), values(v) {}
	~SingleOption() { }
	sf::Text text;
	sf::Vector3i values;
};