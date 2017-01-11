#pragma once

#include "SingleOption.hpp"
#include <vector>

class OptionsMenu
{
public:
	OptionsMenu();
	~OptionsMenu();
	void draw(sf::RenderWindow& window) const;
	std::vector<SingleOption> options;
	
};