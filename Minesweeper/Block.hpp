#ifndef BLOCK_HPP
#define BLOCK_HPP

#include <SFML/Graphics.hpp>
#include "string"

class Block
{
public:
    Block();
    Block(sf::Texture& t, sf::Vector2f& p);
    ~Block();
    sf::Sprite *sprite;
    void setPossition(sf::Vector2f& p);
    void setTexture(sf::Texture& t);
    void setTexturePos(sf::Vector2i& p);
    void setSize(sf::Vector2i& f);
protected:
    sf::Texture *texture;
    sf::Vector2i spritePos;
    sf::Vector2i size;
    sf::Vector2f possition;
    sf::Vector2f scale;
    void updateSprite();
    
};

#endif