#pragma once

#include <vector>
#include "string"
#include "iostream"
#include <SFML/Graphics.hpp>

#define print(a) std::cout << a << std::endl

class InputBox
{
	public:
		InputBox(std::string s = "");
		void setFont(const sf::Font& f);
		void add(char c);
		void remove();
		int getVal() const;
		void draw(sf::RenderWindow& window);
		void setPosition(int x, int y);
		sf::FloatRect getGlobalBounds() const;
		int size() const;
		void reset();
	private:
		std::string val;
		sf::Text text;
};