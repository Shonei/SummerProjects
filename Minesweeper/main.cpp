#include "main.hpp"

int main(int argc, char const *argv[])
{
	// OptionsMenu *optionsMenu = new OptionsMenu();	

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
	        // Request for closing the window
	        if (event.type == sf::Event::Closed)
	        {
	        	window.close();
	        }
	        if(!game.loose)
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
	        else
	        {
	        	if(event.type == sf::Event::KeyPressed)
	        	{
	        		if(event.key.code == sf::Keyboard::R)
	        		{
	        			game.restartGame();
	        			viewSize = game.getViewSize();

	        			view.reset(sf::FloatRect(0, 0, viewSize.x, viewSize.y));
    					window.setSize(sf::Vector2u(viewSize.x, viewSize.y));

    					window.setView(view);

    					game.loose = false;
	        		}
	        		else if(event.key.code == sf::Keyboard::Escape)
	        		{

	        		}
	        	}
	        }
	    }

	    //handels screen rendering dont mess with for now
	    // set backgound colour 
	    window.clear(sf::Color(0, 0, 0, 255));

	   	game.draw(window);
	   	// optionsMenu->draw(window);
		window.display();

    }

	return 0;
}

// you will need it later trust me
// if (event.type == sf::Event::Resized)

// void loosingLoop(sf::RenderWindow& window)
// {
	
// 	std::string name[5] = {"images/0.jpg",
// 						"images/1.png",
// 						"images/2.png",
// 						"images/3.jpg",
// 						"images/4.png"};

// 	std::vector<sf::Sprite> looseV;
// 	std::vector<sf::Texture> looseT;
// 	looseT.resize(5);
// 	looseV.resize(5);


// 	for (int i = 0; i <= 4; ++i)
// 	{
// 		looseT[i].loadFromFile(name[i]);
// 		looseV[i].setTexture(looseT[i]);
// 		looseV[i].setScale(
// 							6*Block.textSize*0.2 / looseV[i].getGlobalBounds().width,
// 							6*Block.textSize*0.2 / looseV[i].getGlobalBounds().height);
// 	}

// 	for (int i = 0; i <= 4; ++i)
// 	{
// 		window.clear(sf::Color(0, 0, 0, 255));
// 		window.draw(looseV[i]);
// 		window.display();
// 		sf::sleep(sf::seconds(2));
// 	}

//     looseV.clear();
//     looseT.clear();

// 	window.close();
// }