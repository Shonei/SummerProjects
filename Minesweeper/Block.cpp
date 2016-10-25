#include "Block.hpp"

Block::Block()
{
    // to be continue
}

Block::Block(sf::Texture& t, sf::Vector2f p, bool x, sf::IntRect r)
{
    mine = x;

    rect = r;

    sprite.setTexture(t);

    sprite.setTextureRect(r);

    sprite.setPosition(p);

    sprite.setScale(0.5f, 0.5f);

}

Block::~Block()
{
    
}
