#pragma once

#include <vector>
#include "iostream"
#include "string"
#include "Option.hpp"
#include "InputBox.hpp"

class OptionsMenu
{
	public:
		OptionsMenu();
		~OptionsMenu();
		void draw(sf::RenderWindow& window);
		void handleEvent(sf::Event event);
		sf::Vector3f getSettings();
		void setInitialValues();
		void setPosition(int x, int y);
	private:
		InputBox input1;
		InputBox input2;
		InputBox input3;
		sf::Font font;		
		std::vector<Option> option;
		sf::Vector3f returnValue;
		int activeIndex;
};