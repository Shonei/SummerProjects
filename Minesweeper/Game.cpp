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
		grid[i-1] = Block(texture, f, false, sf::IntRect(105, 105, 104, 104), scale);

		f.x += 105*scale;
		if(i % w == 0)
		{
			f.x = 0;
			f.y += 105*scale;
		}
	}
	// Seed with a real random value, if available
    std::random_device r;
 
    // Choose a random mean between 1 and 6
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, h*w);

	for(int i = 0; i < mines; i++)
	{
		int rand = uniform_dist(e1);
		grid[rand].mine = true;
		for (int i = -1; i < 2; ++i)
		{
			grid[rand+i+6].nearMines += 1;
			grid[rand+i-6].nearMines += 1;
		}
	}

	// for (int i = 0; i < h*w; ++i)
	// {
	// 	if(grid[i].nearMines != 0)
	// 	{
	// 		grid[i].setSpriteRect(sf::IntRect(0, 105*grid[i].nearMines, 
	// 											104, 104));
	// 	}
	// }
}

int Game::getGridSize()
{
	return grid.size();
}

void Game::mouseClick(sf::Vector2f t)
{
	for (int i = 0; i < grid.size(); i++)
	{
		sf::FloatRect temp = grid[i].sprite.getGlobalBounds();
		if(temp.contains(t))
		{
			grid[i].setSpriteRect(sf::IntRect(0, 0 , 104, 104));
		}

		// sf::IntRect temp;
		// if(temp.intersects(grid[i].sprite.getGlobalBounds(), t))
		// {
		// 	grid[i].setSpriteRect(sf::IntRect(0, 0 , 104, 104));
		// }
	}
}

// still not sure where this will go
// or what parameters it will take
void Game::updateGridTexture()
{

}

Game::~Game()
{
	grid.clear();
}
