#include "Block.hpp"

Block::Block()
{
    // I have yeat to implement the default constructor
    // if anyone ever re uses this code please implement it to m
    // match what you need
    // to be continue
}

Block::Block(sf::Texture& t, sf::Vector2f p, bool x, float s)
{
    mine = x;

    sprite.setTexture(t);

    // the rect below gives a set texture for all blocks
    sprite.setTextureRect(sf::IntRect(textSize, textSize, 104, 104));

    sprite.setPosition(p);

    sprite.setScale(s, s);

    opened = false;

}

Block::~Block()
{
    
}

// avoid me having to use onject.sprite.setTextureRect()
void Block::setSpriteRect(sf::IntRect r)
{
    sprite.setTextureRect(r);
}
