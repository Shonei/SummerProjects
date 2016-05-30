#include "Game.hpp"

Game::Game()
{
	window = new RenderWindow(VideoMode(840, 600), "Too Deep");

	//window->setFramerateLimit(30);

	shape = new Rectangle(425, 295, 0);

	window->clear(Color(255, 255, 255, 255));
}

Game::~Game()
{
	delete window;
	delete shape;
}

void Game::render()
{
	window->setActive();

	window->draw(shape->rec);

	colourRow();

	window->display();
}

void Game::colourRow()
{
	int x = 0;
	for( int i = 0; i < 12; i++ )
	{
		Rectangle temp( x, 0, i);
		window->draw(temp.rec);
		x += 70;
	}
}

void Game::somethingHappened()
{
	window->pollEvent(event); 

	if(event.type == Event::KeyPressed)
	{
		//cout << "key prressed" ;
		if(event.key.code == Keyboard::Left)
		{
			cout << " left key pressed \n";
			m.left = true;	
		}
		else if(event.key.code == Keyboard::Right)
		{
			m.right = true;	
		}
		else if(Keyboard::Up)
		{
			m.up = true;	
		}
		else if(Keyboard::Down)
		{
			m.down = true;	
		}

		shape->move(m);
	}
	else if(event.type == Event::KeyReleased)
	{
		if(event.key.code == Keyboard::Left)
		{
			cout << "left key released \n";
			m.left = false;	
		}
		else if(Keyboard::Right)
		{
			m.right = false;	
		}
		else if(Keyboard::Up)
		{
			m.up = false;	
		}
		else if(Keyboard::Down)
		{
			m.down = false;	
		}

		shape->move(m);
	}
	else if(event.type == Event::MouseLeft)
	{
		if (Mouse::Left)
		{
			mouse();
		}

	}
	else if(event.type == sf::Event::Closed)
	{
		//cout << "Why\n" ;
		//window->close();
	}
}

bool Game::gameOn()
{
	if(window->isOpen())
	{
		return true;
	}

	return false;
}

void Game::mouse()
{
	Vector2i localPosition = Mouse::getPosition();

	int x = localPosition.x;
	int y = localPosition.y;

	if( x > 0 && y > 0 && x < 840 && y < 600 )
	{
		int p = 70;
		for( int i = 0; i < 12; i++ )
			{
				if( x < 70 )
				{
					shape->changeColor(i);
				}
				p += 70;
			}
	}	
}
