#include "Block.hpp"
#include "Game.hpp"
#include "vector"
#include "iostream"

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(400, 600), "Minesweeper");

	window.EnableKeyRepeat(false);
	window.SetFrameraeLimit(30);

    Game game(0.2, 3, 3, 0, "images/blocks.png");

    while(window.isOpen())
    {
    	// Event processing
	    sf::Event event;
	    while (window.pollEvent(event))
	    {
	        // Request for closing the window
	        if (event.type == sf::Event::Closed)
	        {
	        	window.close();
	        }
	    }

	    // set backgound colour 
	    window.clear(sf::Color(0, 0, 0, 255));

	   	for(int i = 0; i < game.getGridSize(); i++ )
		{
			window.draw(game.grid[i].sprite);
		}

		window.display();
    }



	return 0;
}