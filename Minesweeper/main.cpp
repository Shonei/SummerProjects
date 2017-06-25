#include "main.hpp"

bool optionsActive = false;

int main(int argc, char const *argv[])
{	
	Game game(hight, width, mines);

	viewSize = game.getViewSize();

	sf::RenderWindow window(sf::VideoMode(400, 600), "Minesweeper", sf::Style::Close);

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(30);

    // ajustes the view to my window to fit the grid
    view.reset(sf::FloatRect(0, 0, viewSize.x, viewSize.y));
    window.setSize(sf::Vector2u(viewSize.x, viewSize.y));

    window.setView(view);

    while(window.isOpen())
    {
    	// Event processing
	    sf::Event event;
	    while (window.pollEvent(event))
	    {

	        if (event.type == sf::Event::Closed)
	        {
	        	window.close();
	        }
	        
	        if(event.type == sf::Event::KeyPressed)
	       	{
	       		if(event.key.code == sf::Keyboard::R)
	       		{
	       			game.restartGame();
    				game.loose = false;
        		}
	        	else if(event.key.code == sf::Keyboard::Escape)
	        	{
				   	optionsActive = !optionsActive;
				   	options.setPosition(window.getSize().x, window.getSize().y);

				   	if(!optionsActive)
				   	{
				   		sf::Vector3f temp = options.getSettings();

				   		if(temp.x < 0 || temp.y < 0)
				   		{
				   			break;
				   		}
				   		print(temp.z);
				   		game.updateGrid(temp.x, temp.y, temp.z);

				   		game.loose = false;
				   		
						viewSize = game.getViewSize();

					    view.reset(sf::FloatRect(0, 0, viewSize.x, viewSize.y));
					    window.setSize(sf::Vector2u(viewSize.x, viewSize.y));

					    window.setView(view);

				   		game.restartGame();
				   	}
        		} 
	       	}
	        
	        if(!game.loose && !optionsActive)
	        {
	        	game.eventHandler(event);
	        	if(game.gameEnd())
	        	{
	        		/*
	        			Use for win condition
	        			Move outside the event loop
	        			Give the player a reward
	        		*/
	        	}
	        }
	        else if (optionsActive)
	        {
	        	options.handleEvent(event);
	        }

	    }

		window.clear(sf::Color(0, 0, 0, 255));
	    
	    if(optionsActive){
			options.draw(window);
	    	
	    } else 
	    {
	  	   	game.draw(window);
	    }

		window.display();
    }

	return 0;
}

