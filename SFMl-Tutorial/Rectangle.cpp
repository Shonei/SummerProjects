#include "Rectangle.hpp"

// sets the color and possition of the rrectangle on creation
Rectangle::Rectangle(int Px, int Py, int c)
{
	x = Px;
	y = Py;

	recColor.r = color[c][0];
	recColor.g = color[c][1];
	recColor.b = color[c][2];
	recColor.a = 255;

	rec.setSize(Vector2f(recH, recW));
	rec.setFillColor(recColor);
	rec.setPosition(x, y);
}

// sets the possition and gived black as defaoult colour
Rectangle::Rectangle(int Px, int Py)
{
	x = Px;
	y = Py;

	recColor.r = 255;
	recColor.g = 255;
	recColor.b = 255;
	recColor.a = 255;

	rec.setSize(Vector2f(10, 10));
	rec.setFillColor(recColor);
	rec.setPosition(x, y);
}

Rectangle::~Rectangle()
{
	// I am unsure if I need to clear any memory
}

void Rectangle::changeColor(int c)
{
	recColor.r = color[c][0];
	recColor.g = color[c][1];
	recColor.b = color[c][2];

	rec.setFillColor(recColor);
}

/*
Moves the rectangle based on the values of the Movement data type.
It takes 2 integers to make sure to keep the rectangle inside the screen boundary. 
*/
void Rectangle::move(Movement m, int SX, int SY)
{
	if(m.left && x > 0)
	{
		x -= velocity;
	}
	else if(m.right && x < SX - recW)
	{
		x += velocity;
	}

	if(m.up && y > 50)
	{
		y -= velocity;
	}
	else if(m.down && y < SY - recH)
	{
		y += velocity;
	}

	rec.setPosition(x, y);
}