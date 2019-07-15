/* 
	This is my representation of a rectangle in SFML.
	I have added 2 methods that move the rectangle on the screen and change the color.
	There are 2 constructors. One takes only coordinates 
	and the seconds one needs a third int for the color. 
	All the colors are stored in an array. 
	I have decided to make the rectangle shape provided from SFML public. 
*/

#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "Struct.hpp"
#include "iostream"

using namespace sf;
using namespace std;
class Rectangle
{
	public:
		Rectangle(int x, int y, int c);
		Rectangle(int x, int y);
		~Rectangle();
		RectangleShape rec;
		void changeColor(int c);
		void move(Movement m, int SX, int SY);
	private:
		int x;
		int y;
		Color recColor;
		int color[12][3] = 
		{
			{ 0, 0, 0},       // black
			{255, 255, 255},  // white
			{0, 0, 255},      // blue
			{0, 255, 0},      // green
			{255, 0, 0},      // red
			{255, 255, 0},    // yellow
			{255, 55, 185},   // pink
			{145, 5, 190},    // purple
			{255, 120, 0},    // orange
			{10, 215, 230},   // white-blue
			{20, 120, 15},    // dark-green
			{135, 70, 10}     // brown
		};

		// values for how big the rectangle is and the speed it moves at
		int velocity = 2;
		int recH = 10;
		int recW = 10;
};

#endif