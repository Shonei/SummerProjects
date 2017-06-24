#pragma once

#include <vector>
#include "iostream"
#include "string"
#include "Option.hpp"

class OptionsMenu
{
	public:
		OptionsMenu();
		~OptionsMenu();
		void draw(sf::RenderWindow& window);
		void handleEvent(sf::Event event);
		sf::Vector3f getSettings();
		void setInitialValues();
	private:
		sf::Font font;		
		std::vector<Option> option;
		sf::Vector3f returnValue;
		int activeIndex;
};