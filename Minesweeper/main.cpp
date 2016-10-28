#include "Block.hpp"
#include "Game.hpp"
#include "vector"
#include "iostream"
int hight = 6;
int width = 6;
sf::View view;

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(400, 600), "Minesweeper");

	window.setKeyRepeatEnabled(false);
	window.setFramerateLimit(30);

    Game game(0.2, hight, width, 5, "images/blocks.png");

    // ajustes the view to my window to fit the grid
    view.reset(sf::FloatRect(0, 0, width*105*game.scale, hight*105*game.scale));
    window.setSize(sf::Vector2u(width*105*game.scale, hight*105*game.scale));

    window.setView(view);

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

	        if (event.type == sf::Event::MouseButtonPressed)
	        {
	        	if (event.mouseButton.button == sf::Mouse::Left)
	        	{
	        		game.mouseClick(sf::Vector2f(event.mouseButton.x,
	        									 event.mouseButton.y));
	        	}
	        }
	    }

	    //handels screen rendering dont mess with for now
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

// you will need it later trust me
// if (event.type == sf::Event::Resized)