#include "Block.hpp"
#include "Game.hpp"
#include "vector"
#include "iostream"
#include "string"

void loosingLoop(sf::RenderWindow& window);

int hight = 6;
int width = 6;
sf::View view;
bool loose = false;

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
	        									 event.mouseButton.y), loose);
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

		if(loose)
		{
			loosingLoop(window);
		}
    }

	return 0;
}

// you will need it later trust me
// if (event.type == sf::Event::Resized)

void loosingLoop(sf::RenderWindow& window)
{
	
	std::string name[5] = {"images/0.jpg",
						"images/1.png",
						"images/2.png",
						"images/3.jpg",
						"images/4.png"};

	std::vector<sf::Sprite> looseV;
	std::vector<sf::Texture> looseT;
	looseT.resize(5);
	looseV.resize(5);


	for (int i = 0; i <= 4; ++i)
	{
		looseT[i].loadFromFile(name[i]);
		looseV[i].setTexture(looseT[i]);
		looseV[i].setScale(
							6*105*0.2 / looseV[i].getGlobalBounds().width,
							6*105*0.2 / looseV[i].getGlobalBounds().height);
	}

	for (int i = 0; i <= 4; ++i)
	{
		window.clear(sf::Color(0, 0, 0, 255));
		window.draw(looseV[i]);
		window.display();
		sf::sleep(sf::seconds(2));
	}

    looseV.clear();
    looseT.clear();

	window.close();
}