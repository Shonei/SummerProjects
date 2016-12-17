/*
	This is biggest part of the grid that needs changes.
	To be fair deleting it and starting anew will be best.

	Right now it holds that window and grid onject as well
	as the grid and event loops.

	I am considering af creating a main object and having methods to futher 
	seperate the code to make it easier to understand.
*/

#include "Block.hpp"
#include "Grid.hpp"
#include "Game.hpp"
#include "vector"
#include "iostream"
#include "string"

void loosingLoop(sf::RenderWindow& window);

bool loose = false;
sf::View view;
GridInfo gridInfo;
sf::Vector2f viewSize;
int hight = 6;
int width = 6;
