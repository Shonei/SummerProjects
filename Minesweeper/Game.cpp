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

	// clear grid to be sure and set the new size
	grid.clear();

	// set new size according to the height and width 
	grid.resize(h*w);

	// initialise a vector to set the sprite possition
	// 0, 0 for the first sprite
	sf::Vector2f f(0, 0);

	// creates the grid 
	for(int i = 1; i <= h*w ; i++ )
	{
		grid[i-1] = Block(texture, f, false, scale);

		// move each sprite 105 pixels each time
		f.x += 105*scale;

		// move to next row in grid
		if(i % w == 0)
		{
			f.x = 0;
			f.y += 105*scale;
		}
	}

	// puts mines in random blocks
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, h*w);

	for(int i = 0; i < mines; i++)
	{
		int rand = uniform_dist(e1);

		grid[rand].mine = true;

		/*
			fror my tests the next part of the method does not work.
			I will have to change it or better complete re do it.
		*/

		// updates the nearMines values to  the blocks that 
		// are next to mines 
		grid[rand+1].nearMines += 1;
		grid[rand-1].nearMines += 1;

		// should change the mines count value of block next to a mine 
		for (int i = -1; i < 2; ++i)
		{
			grid[rand+i+w].nearMines += 1;
			grid[rand+i-w].nearMines += 1;
		}
	}
}

int Game::getGridSize()
{
	return grid.size();
}

void Game::mouseClick(sf::Vector2f t, bool& l)
{
	/*
		goes through the how grid reading the bounds of the sprite and
		then checkes if the mouse click intersects any on them.

		once it has found an intersection it chnages the texture rect
		accordingly.
	*/
	for (int i = 0; i < grid.size(); i++)
	{
		sf::FloatRect temp = grid[i].sprite.getGlobalBounds();
		if(temp.contains(t))
		{
			if(!grid[i].mine)
			{		
				// if there are mines near it it will change the texture rect
				// to the according number	
				if( grid[i].nearMines > 0 )
				{
					grid[i].setSpriteRect(sf::IntRect((grid[i].nearMines-1)*105, 0, 104, 104));
				}
				// if there are no near mines it sets it to a blank block
				else
				{
					grid[i].setSpriteRect(sf::IntRect(0, 105, 104, 104));
				}
			}
			else
			{
				// sets loosing condition and puts sprite rect to a mine
				l = true;
				grid[i].setSpriteRect(sf::IntRect(315, 105, 104, 104));
			}
		}
	}
}

Game::~Game()
{
	grid.clear();
}
