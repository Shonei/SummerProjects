#pragma once 

#include "InputBox.hpp"

class InputOption
{
	public:
		InputOption();
		void setFont(const sf::Font& f);
		void setPosition(const int x, const int y);
		void draw(sf::RenderWindow& window);
		void updateActiveIndex(const int i);
		void handleEvent(const sf::Event& event);
		sf::Vector3f getVal();
		bool isIctivated(const int x, const int y);
		void setColor(const sf::Color& c);
	private:
		std::vector<InputBox> inputs;
		int activeIndex;
		sf::RectangleShape rectangle;	
		void checkActiveIndex();
};