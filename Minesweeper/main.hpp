#include "OptionsMenu.hpp"
#include "Game.hpp"
#include "vector"
#include "iostream"
#include "string"

void loosingLoop(sf::RenderWindow& window);

bool loose = false;
sf::View view;
GridInfo gridInfo;
sf::Vector2f viewSize;
OptionsMenu options;
int hight = 10;
int width = 10;
int mines = 5;

