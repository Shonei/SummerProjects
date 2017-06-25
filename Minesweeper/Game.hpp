#pragma once

#include "Grid.hpp"
#include "Block.hpp"

class Game
{
	public:
		sf::Vector2f getViewSize() const;
		bool loose;
		Game(int h, int w, int m);
		void eventHandler(const sf::Event &event);
		void draw(sf::RenderWindow &window) const; 
		bool gameLoose() const;
		void restartGame();
		void updateGrid(float w, float h, float m);
		bool gameEnd();
	private:
		Grid grid;
		GridInfo gridInfo;

};