#include "Game.hpp"

Game::Game(float t, 
			int h,
			int w, 
			int mines, 
			std::string name)
{
	scale = t;
	if(!texture.loadFromFile(name))
	{
		sf::err();
		// probably close the file at this point
		// or try to fix the error
	}

	resizeGrid(h, w, mines, scale);

}

void Game::resizeGrid(int h, int w, int mines, float s)
{
	scale  = s;

	grid.clear();

	grid.resize(h*w);

	sf::Vector2f f(0, 0);

	// the next for loop might need < instead of <=
	for(int i = 1; i <= h*w ; i++ )
	{
		grid[i-1] = Block(texture, f, false, sf::IntRect(0, 105, 103, 104), scale);

		f.x += 105*scale;
		if(i % w == 0)
		{
			f.x = 0;
			f.y += 105*scale;
		}
	}
}

int Game::getGridSize()
{
	return grid.size();
}

void Game::mouseClick(sf::Vector2i t)
{
	for (int i = 0; i < grid.size(); i++)
	{
		if(grid[i].rect.contains(t))
		{
			// change sprite to reveal the name
		}
	}
}

Game::~Game()
{
	grid.clear();
}