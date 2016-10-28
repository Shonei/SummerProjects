#include "Block.hpp"

Block::Block()
{
    // to be continue
}

Block::Block(sf::Texture& t, sf::Vector2f p, bool x, float s)
{
    mine = x;

    sprite.setTexture(t);

    // the rect below gives a set texture for all blocks
    sprite.setTextureRect(sf::IntRect(105, 105, 104, 104));

    sprite.setPosition(p);

    sprite.setScale(s, s);

}

Block::~Block()
{
    
}

void Block::setSpriteRect(sf::IntRect r)
{
    sprite.setTextureRect(r);
}
