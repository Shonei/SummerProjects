/*
    Header file to represent a block from the game minesweeper.
    It will contain the sprite, whether or not it is a mine
    or how many mines are near it.
    the setSpriteRect method is just to make changing the possition on 
    the sprite easier.
*/



#pragma once

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block();
    Block(sf::Texture& t, sf::Vector2f p, bool x, float s);
    ~Block();
    void setSpriteRect(sf::IntRect r);
    int nearMines = 0;
    bool mine;
    sf::Sprite sprite;
};