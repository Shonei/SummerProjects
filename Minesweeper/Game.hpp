#pragma once

#include "Grid.hpp"
#include "Block.hpp"

class Game
{
public:
	Game(int h, int w, int m);
	~Game();
	void eventHandler(const sf::Event &event);
	void draw(sf::RenderWindow &window) const; 
	bool gameLoose() const;
	sf::Vector2f getViewSize() const;
	Grid *grid;
	GridInfo gridInfo;
	bool loose;
	
};