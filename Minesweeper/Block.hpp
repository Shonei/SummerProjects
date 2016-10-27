#pragma once

#include <SFML/Graphics.hpp>

class Block
{
public:
    Block();
    Block(sf::Texture& t, sf::Vector2f p, bool x, sf::IntRect r, float s);
    ~Block();
    bool mine;
    sf::Sprite sprite;
    sf::IntRect rect;
};