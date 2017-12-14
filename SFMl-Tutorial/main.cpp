#include <SFML/Graphics.hpp>
#include "Game.hpp"
#include "iostream"

using namespace sf;
using namespace std;

int main()
{
    // define a 120x50 rectangle
    sf::RectangleShape rectangle(sf::Vector2f(120, 50));

    // change the size to 100x100
    rectangle.setSize(sf::Vector2f(100, 100));
}