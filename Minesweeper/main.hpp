#include "Block.hpp"
#include "Grid.hpp"
#include "Game.hpp"
#include "OptionsMenu.hpp"
#include "vector"
#include "iostream"
#include "string"

void loosingLoop(sf::RenderWindow& window);

bool loose = false;
sf::View view;
GridInfo gridInfo;
sf::Vector2f viewSize;
int hight = 20;
int width = 20;
int mines = 10;

