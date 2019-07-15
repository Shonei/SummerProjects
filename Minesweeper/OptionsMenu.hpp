#pragma once

#include <vector>
#include "iostream"
#include "string"
#include "Option.hpp"
#include "InputBox.hpp"
#include "InputOption.hpp"

class OptionsMenu
{
	public:
		OptionsMenu();
		void draw(sf::RenderWindow& window);
		void handleEvent(const sf::Event& event);
		sf::Vector3f getSettings();
		void setInitialValues();
		void setPosition(int x, int y);
	private:
		InputOption input;
		sf::Font font;		
		std::vector<Option> option;
		sf::Vector3f returnValue;
		int activeIndex;
};