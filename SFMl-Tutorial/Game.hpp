/*
    There is only one constructor that creates the window and the custom rectangle 
    I had previously created.
    The memory allocated is relesead in the destructor.
    There are 3 public methods. 
    render renders the screen with the applied changes.
    somethingHappened reads the input and makes changes accordingly.
    gameOn is used as a condition to keep the game running.
    I have 2 private methods.
    colourRow renders the colout choices on top of the screen.
    mouse handels mouse input so the user could change colours. 
*/

#ifndef GAME_HPP
#define GAME_HPP

#include <SFML/Graphics.hpp>
#include "Rectangle.hpp"
#include "iostream"

using namespace sf;
using namespace std;

class Game
{
	public:
		Game();
		~Game();
		void render();
		void somethingHappened();
		bool gameOn();
	private:
		Rectangle *shape;
		RenderWindow *window;
		void colourRow();
		void mouse();
		Event event;
		Movement m;
		const int screenW = 840;
		const int screenH = 600;
};

#endif