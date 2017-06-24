#include "Block.hpp"

Block::Block()
{

}

Block::Block(sf::Texture& t, sf::Vector2f p, bool x, float s)
{
    mine = x;

    sprite.setTexture(t);

    sprite.setTextureRect(sf::IntRect(textSize, textSize, 104, 104));

    sprite.setPosition(p);

    sprite.setScale(s, s);

    opened = false;

}

Block::~Block()
{
    
}

void Block::setSpriteRect(sf::IntRect r)
{
    sprite.setTextureRect(r);
}
