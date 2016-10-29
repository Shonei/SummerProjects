#include <SFML/Graphics.hpp>

int main(int argc, char const *argv[])
{
	sf::RenderWindow window(sf::VideoMode(400, 600), "Minesweeper");
	sf::Texture t;
	t.loadFromFile("images/0.jpg");
	sf::Sprite s(t);

	s.setScale(400 / s.getGlobalBounds().width, 600 / s.getGlobalBounds().height);

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

	    //handels screen rendering dont mess with for now
	    // set backgound colour 
	    window.clear(sf::Color(0, 0, 0, 255));

			window.draw(s);
		

		window.display();

    }

	return 0;
}