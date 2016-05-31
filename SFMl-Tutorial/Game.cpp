#include "Game.hpp"

Game::Game()
{
	window = new RenderWindow(VideoMode(screenW, screenH), "Too Deep");

	window->setFramerateLimit(60);

	shape = new Rectangle((screenW / 2) - 5, (screenH / 2) - 5, 0);

	window->clear(Color(255, 255, 255, 255));

	window->setKeyRepeatEnabled(false);
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
		temp.rec.setSize(Vector2f(70, 50));
		window->draw(temp.rec);
		x += 70;
	}
}

void Game::somethingHappened()
{
	while (window->pollEvent(event))
	{
	    // check the type of the event...
	    switch (event.type)
	    {
	        // window closed
	        case Event::Closed:
	            window->close();
	            break;

	        // key pressed
	        case Event::KeyPressed:
	        {	
            	if (Keyboard::isKeyPressed(Keyboard::Left))
				{
					m.left = true;	
					m.right = false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Right))
				{
					m.right = true;	
					m.left = false;
				}
				
				if (Keyboard::isKeyPressed(Keyboard::Up))
				{
					m.up = true;	
					m.down = false;
				}
				else if (Keyboard::isKeyPressed(Keyboard::Down))
				{
					m.down = true;	
					m.up = false;
				}
	            break;
	        }

	        // key released 
	        case Event::KeyReleased:
	        {	
            	if (event.key.code == Keyboard::Left)
				{
					m.left = false;	
				}
				else if (event.key.code == Keyboard::Right)
				{
					m.right = false;	
				}
				
				if (event.key.code == Keyboard::Up)
				{
					m.up = false;	
				}
				else if (event.key.code == Keyboard::Down)
				{
					m.down = false;	
				}
	            break;
	        }

	        case Event::MouseButtonPressed:
	        	if(event.mouseButton.button == Mouse::Left)
	        	{
		        	cout << "mouse left click\n";
		        	mouse();
		        	break;
	        	}
	    }
	}

	shape->move(m, screenW, screenH);
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
	int x = event.mouseButton.x;
	int y = event.mouseButton.y;

	if( x > 0 && y > 0 && x < screenW && y < screenH )
	{
		int p = 70;
		for( int i = 0; i < 12; i++ )
			{
				if( x < p )
				{
					cout << i << " - color\n";
					shape->changeColor(i);
					break;
				}
				p += 70;
			}
	}	
}
