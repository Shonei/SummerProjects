#include "Game.hpp"

Game::Game(int h, int w, int m)
{
	gridInfo.texture = "images/blocks.png";
	gridInfo.scale = 0.2;
	gridInfo.hight = h;
	gridInfo.width = w;
	gridInfo.mines = m;
	loose = false;

	grid = new Grid(gridInfo);
}

void Game::eventHandler(const sf::Event &event)
{
	if (event.type == sf::Event::MouseButtonPressed)
	        {
	        	if (event.mouseButton.button == sf::Mouse::Left)
	        	{
	        		grid->mouseClick(sf::Vector2f(event.mouseButton.x,
	        									 event.mouseButton.y), loose);
	        	}
	        	else if(event.mouseButton.button == sf::Mouse::Right)
	        	{
	        		grid->mouseRightClick(sf::Vector2f(event.mouseButton.x,
	        									 event.mouseButton.y));
	        	}
	        }
}

void Game::draw(sf::RenderWindow &window) const
{
	for(int i = 0; i < grid->getGridSize(); i++ )
	{
		window.draw(grid->grid[i].sprite);
	}
}

sf::Vector2f Game::getViewSize() const
{
	sf::Vector2f temp;
	temp.x = gridInfo.width*Block::textSize*gridInfo.scale;
	temp.y = gridInfo.hight*Block::textSize*gridInfo.scale;

	return temp;
}

void Game::restartGame()
{
	grid->resizeGrid(gridInfo);
}

bool Game::gameEnd()
{
	for(Block i: grid->grid)
	{
		if(!i.mine && !i.opened)
		{
			return false;
		}
	}

	return true;
}

Game::~Game()
{
	delete grid;
}