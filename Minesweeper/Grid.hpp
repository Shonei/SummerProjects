/*
	Definition of a Grid class that will handle creating the grid.
	I should have named it grid as it only hold the grid of blocks.
	It has 4 methods. 
	resizeGrid is used for both craeting the grid initialy 
	and later on to change it if needed.
	mouseClick handles mouse input.
*/

#pragma once

#include <SFML/Graphics.hpp>
#include "vector"
#include "Block.hpp"
#include "string"
#include "ctime"
#include "random"
#include "iostream"

class Grid
{
	public:
		Grid();
		Grid(float t = 1.0, 
			 int h = 5,
			 int w = 5, 
			 int mines = 5, 
			 std::string name = "");
		~Grid();
		std::vector<Block> grid;
		float scale = 1.0;
		sf::Texture texture;
		void resizeGrid(int h, int w,int mines, float scale); 
		int getGridSize(); const
		void mouseClick(sf::Vector2f t, bool& l);

};
