#include "Game.hpp"

Game::Game()
{
	window = new RenderWindow(VideoMode(screenW, screenH), "Too Deep");

	window->setFramerateLimit(60);

    // sets the rectangle shape on the middle of the screen
	shape = new Rectangle((screenW / 2) - 5, (screenH / 2) - 5, 0);

    // renders the clour of the screen white
	window->clear(Color(255, 255, 255, 255));

    // makes it so key presses are detected only once
	window->setKeyRepeatEnabled(false);
}

Game::~Game()
{
    // clears allocated memory
	delete window;
	delete shape;
}

void Game::render()
{   
    // I am not entierly sure what this does
    // The game appears to work evven it is not included
	window->setActive();

    // renders the rectangle
	window->draw(shape->rec);

	colourRow();

	window->display();
}

void Game::colourRow()
{
    // loops through the array of colours and renders them on top of the screen
	int x = 0;
	for( int i = 0; i < 12; i++ )
	{
        // it creates a temporary rectangle that is used to display the colour row
		Rectangle temp( x, 0, i);
		temp.rec.setSize(Vector2f(70, 50));
		window->draw(temp.rec);
		x += 70;
	}
}

/*
Loops through all the events that had occured 
The switch statemnt is used to do the accorrding action
*/
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

    // checks if the user has clicked inside the colour row on top of the screen
    // then it loops through all the colours using coordinates
    // to find where the user has clicked and change the colour accordingly
    // once the click has been found it changes the colour
	if( x > 0 && y > 0 && x < screenW && y < 50 )
	{
		int p = 70;
		for( int i = 0; i < 12; i++ )
			{
				if( x < p )
				{
					shape->changeColor(i);
					break;
				}
				p += 70;
			}
	}	
}
