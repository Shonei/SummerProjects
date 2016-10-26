#include "Game.hpp"

Game::Game(float t = 1.0, 
			int size = 25, 
			int mines = 5, 
			std::string name("images/blocks.png"))
{
	scale = t;
	if(!texture.loadFromFile(name))
	{
		sf::err();
		// probably close the file at this point
		// or try to fix the error
	}

	resizeGrid(s, m);

}

void Game::resizeGrid(int size, int mines)
{
	grid.clear();

	grid.resize(size);

	for(int i = 0; i <= size ; i++ )
	{
		grid[i] = Block(texture, f, true, sf::IntRect(k, 0, 103, 104));
		k += 105;
		f.y += 105*0.5;
	}
}