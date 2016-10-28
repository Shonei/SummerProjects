#pragma once

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block();
    Block(sf::Texture& t, sf::Vector2f p, bool x, sf::IntRect r, float s);
    ~Block();
    void setSpriteRect(sf::IntRect r);
    int nearMines = 0;
    bool mine;
    sf::Sprite sprite;
    sf::IntRect rect;
};