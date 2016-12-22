#include "Grid.hpp"

Grid::Grid(GridInfo &info)
{
	width = info.width;
	hight = info.hight;

	scale = info.scale;
	if(!texture.loadFromFile(info.texture))
	{
		sf::err();
		// probably close the file at this point
		// or try to fix the error
	}

	resizeGrid(info);
}

void Grid::resizeGrid(GridInfo &info)
{
	scale  = info.scale;

	// clear grid to be sure and set the new size
	grid.clear();

	// set new size according to the height and width 
	grid.resize(info.width * info.hight);

	// initialise a vector to set the sprite possition
	// 0, 0 for the first sprite
	sf::Vector2f f(0, 0);

	// creates the grid 
	for(unsigned int i = 1; i <= grid.size() ; i++ )
	{
		grid[i-1] = Block(texture, f, false, info.scale);

		// move each sprite Block::textSize pixels each time
		f.x += Block::textSize*info.scale;

		// move to next row in grid
		if(i % info.width == 0)
		{
			f.x = 0;
			f.y += Block::textSize*info.scale;
		}
	}

	putMines(info);
}

int Grid::getGridSize()
{
	return grid.size();
}

void Grid::mouseClick(sf::Vector2f t, bool l)
{
	/*
		goes through the how grid reading the bounds of the sprite and
		then checkes if the mouse click intersects any on them.

		once it has found an intersection it chnages the texture rect
		accordingly.
	*/
	for (unsigned int i = 0; i < grid.size(); i++)
	{
		sf::FloatRect temp = grid[i].sprite.getGlobalBounds();
		if(temp.contains(t))
		{
			if(!grid[i].mine)
			{		
				revealGrid(grid[i], i);
			}
			else
			{
				// sets loosing condition and puts sprite rect to a mine
				l = true;
				grid[i].setSpriteRect(sf::IntRect(315, Block::textSize, 104, 104));
			}
		}
	}
}

void Grid::mouseRightClick(sf::Vector2f t)
{
	for (unsigned int i = 0; i < grid.size(); i++)
	{
		sf::FloatRect temp = grid[i].sprite.getGlobalBounds();
		if(temp.contains(t))
		{
			if(!grid[i].opened)
			{
				grid[i].setSpriteRect(sf::IntRect(210, Block::textSize, 104, 104));
			}
		}
	}
}
Grid::~Grid()
{
	grid.clear();
}

void Grid::putMines(GridInfo &info)
{
	// puts mines in randomom blocks
    std::random_device r;
    std::default_random_engine e1(r());
    std::uniform_int_distribution<int> uniform_dist(0, info.hight*info.width);

	for(int i = 0; i < info.mines; i++)
	{
		int random = uniform_dist(e1);
		if(!grid[random].mine)
		{
			grid[random].mine = true;

			/*
				from my tests the next part of the method does not work.
				I will have to change it or better complete re do it.

				It goes over the next line of a mine is at a corner of a grid
				same problem for the future reveal grid function
			*/

			if(random < info.width)
			{
				grid[random+info.width].nearMines += 1;
				
				thinkOfABetterName(info.width, random);
			}
			else if(random > (int)grid.size()-info.width)
			{
				grid[random-info.width].nearMines += 1;

				thinkOfABetterName(-info.width, random);
			}
			else
			{
				int temp = 0;
				grid[random+info.width].nearMines += 1;
				grid[random-info.width].nearMines += 1;

				if(random % info.width == 0)
				{
					temp = 1;
				}
				else if((random+1) % info.width == 0)
				{
					temp = -1;
				}	
				else
				{			
					temp = 1;
					grid[random-1].nearMines += 1;
					grid[random-info.width-1].nearMines += 1;
					grid[random+info.width-1].nearMines += 1;
				}

				grid[random+temp].nearMines += 1;
				grid[random+info.width+temp].nearMines += 1;
				grid[random-info.width+temp].nearMines += 1;

			}
		}
	}	
}

void Grid::thinkOfABetterName(int t, int random)
{
	if((random % t) == 0)
	{
		grid[random+1].nearMines += 1;
		grid[random+t+1].nearMines += 1;
	}
	
	if((random+1) % t == 0)
	{
		grid[random-1].nearMines += 1;
		grid[random+t-1].nearMines += 1;
	}
	
	if(((random % t) != 0) && ((random+1 % t) != 0))
	{
		grid[random+1].nearMines += 1;
		grid[random+t+1].nearMines += 1;
		grid[random-1].nearMines += 1;
		grid[random+t-1].nearMines += 1;
	}
}

void Grid::revealGrid(Block &cell, int i)
{
	changeSpriteTexture(cell);

	if(shouldItReveal(grid[i], grid[i+1], i, i+1))
	{
		revealGrid(grid[i+1], i+1);
	}
		
	if(shouldItReveal(grid[i], grid[i-1], i, i-1))
	{
		revealGrid(grid[i-1], i-1);	
	}
		
	if(shouldItReveal(grid[i], grid[i+width], i, i+width))
	{
		revealGrid(grid[i+width], i+width);
	}
		
	if(shouldItReveal(grid[i], grid[i-width], i, i-width))
	{
		revealGrid(grid[i-width], i+width);
	}
}

//changes the texture of a non mine Block
void Grid::changeSpriteTexture(Block &a)
{	
	a.opened = true;

	// if there are mines near it it will change the texture rect
	// to the according number	
	if( a.nearMines > 0 )
	{
		a.setSpriteRect(sf::IntRect((a.nearMines-1)*Block::textSize, 0, 104, 104));
	}
	// if there are no near mines it sets it to a blank block
	else
	{
		a.setSpriteRect(sf::IntRect(0, Block::textSize, 104, 104));
	}
}

bool Grid::shouldItReveal(Block &prev, Block &current, int prevIndex, int currentIndex)
{
	if(prev.nearMines > 0)
	{
		return false;
	}

	if(current.mine)
	{
		return false;
	}

	if(prevIndex < 0)
	{
		return false;
	}

	if(prevIndex > (int)grid.size())
	{
		return false;
	}

	if(currentIndex < 0)
	{
		return false;
	}

	if(currentIndex > (int)grid.size())
	{
		return false;
	}


	if(current.opened)
	{
		return false;
	}

	// // checks if cells are on the same roll
	// if(abs(prevIndex - curentIntex) > 1)
	// {
	// 	if(abs(curentIntex - prevIndex) != width)
	// 	{
	// 		return false;
	// 	}
	// }
	
	// // chacks if cells are on the same column
	// else if(abs(prevIndex - curentIntex) == 1)
	// {
	// 	if(floor(curentIntex / width) != floor(prevIndex / width)) 
	// 	{
	// 		return false;
	// 	}
	// }

	return true;
}