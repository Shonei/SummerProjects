#pragma once

#include <SFML/Graphics.hpp>
#include "vector"
#include "Block.hpp"
#include "string"

class Game
{
	public:
		Game();
		Game(float t = 1.0, 
			 int h = 5,
			 int w = 5, 
			 int mines = 5, 
			 std::string name = "");
		~Game();
		std::vector<Block> grid;
		float scale = 1.0;
		sf::Texture texture;
		void resizeGrid(int h, int w,int mines, float scale);	
		int getGridSize();
		void mouseClick(sf::Vector2i t);

};

// remember to switch repeat buttons off
// dont forget to check if a button is pressed before hand
// will get mouse position for the screen to be used in colition
// sf::Vector2i localPosition = sf::Mouse::getPosition(window);

// this is how I will do colition
// sprite.rect.contains(sf::Vector2i t)