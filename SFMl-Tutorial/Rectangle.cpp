#include <SFML/Graphics.hpp>

using namespace sf;
using namespace std;

class Rectangle
{
	public:
		Rectangle(int x, int y, Color color);
		Rectangle(int x, int y);
		~Rectangle();
		RectangleShape rec;
		void move(Event event);
		void render();
	
	private:
		int x;
		int y;
		Color recColor;
		Color color[11] = 
		{
			(0, 0, 0),        // white
			(0, 0, 255),      // blue
			(0, 255, 0),      // green
			(255, 0, 0),      // red
			(255, 255, 0),    // pink
			(255, 55, 185),   // purple
			(145, 5. 190),    // orange
			(255, 120, 0),    // white-blue
			(10, 215, 230),   // white
			(20. 120, 15),    // dark-green
			(135, 70, 10)     // brown
		};
};

Rectangle(int Px, int Py, int c)
{
	x = Px;
	y = Py;
	recColor = color[c];
}