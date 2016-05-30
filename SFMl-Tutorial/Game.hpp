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
};

#endif