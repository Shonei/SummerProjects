#include "Grid.hpp"

Grid::Grid()
{
	width = 6;
	hight = 6;

	spriteSize = Block::textSize * 0.2;

	scale = 0.2;
}

void Grid::setValues(GridInfo &info)
{
	spriteSize = Block::textSize * info.scale;

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
	width = info.width;
	hight = info.hight;
	scale  = info.scale;

	grid.clear();

	grid.resize(info.width * info.hight);

	sf::Vector2f blockPossition(0, 0);

	// creates the grid 
	for(unsigned int i = 1; i <= grid.size() ; i++ )
	{
		grid[i-1] = Block(texture, blockPossition, false, info.scale);

		// move each sprite Block::textSize pixels each time
		blockPossition.x += Block::textSize*info.scale;

		// move to next row in grid
		if(i % info.width == 0)
		{
			blockPossition.x = 0;
			blockPossition.y += Block::textSize*info.scale;
		}
	}

	putMines(info);
}

int Grid::getGridSize() const
{
	return grid.size();
}

void Grid::mouseClick(sf::Vector2f t, bool &l)
{
	int i = (floor(t.y / spriteSize) * width) + floor(t.x / spriteSize);

	sf::FloatRect temp = grid[i].sprite.getGlobalBounds();
	// print(temp.left);
	// print(temp.top);
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

			int row = floor(random / hight);
			int column = random % width;

			for (int i = row - 1; i <= row + 1; ++i)
			{
				for (int j = column - 1; j <= column + 1; ++j)
					{
						unsigned int index = i * width + j;

						if( index > 0 &&
							index < grid.size() &&
							floor(index / width) == i) 
						{

							grid[index].nearMines += 1;
							// std::cout << index << width << row << std::endl;
						}
					}	
			}
		}
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
		revealGrid(grid[i-width], i-width);
	}
}

//changes the texture of a non mine Block
void Grid::changeSpriteTexture(Block &a)
{	
	a.opened = true;
	
	if( a.nearMines > 0 )
	{
		a.setSpriteRect(sf::IntRect((a.nearMines-1)*Block::textSize, 0, 104, 104));
	}
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

	return true;
}
