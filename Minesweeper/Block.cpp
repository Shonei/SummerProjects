#include "Block.hpp"

Block::Block()
{
    // to be continue
}

Block::Block(sf::Texture& t, sf::Vector2f p, bool x, sf::IntRect r, float s)
{
    mine = x;

    sprite.setTexture(t);

    sprite.setTextureRect(r);

    sprite.setPosition(p);

    sprite.setScale(s, s);

    rect.top = p.y;
    rect.left = p.x;
    rect.width = r.width*s;
    rect.height = r.height*s;

}

Block::~Block()
{
    
}

void Block::setSpriteRect(sf::IntRect r)
{
    sprite.setTextureRect(r);
}
