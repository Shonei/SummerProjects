#pragma once

#include "Grid.hpp"
#include "Block.hpp"

class Game
{
public:
	Game();
	~Game();
	void changeView(); const
	void eventHandler(const sf::Event event); const 
	void draw(sf::Window window); const
	Grid grid;
	
};