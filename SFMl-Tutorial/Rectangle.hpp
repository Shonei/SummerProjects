#ifndef RECTANGLE_HPP
#define RECTANGLE_HPP

#include <SFML/Graphics.hpp>
#include "Struct.hpp"

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
		void move(Movement m);
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
		int velocity = 10;
};

#endif