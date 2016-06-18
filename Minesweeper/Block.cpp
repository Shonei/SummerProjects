#include "Block.hpp"

Block::Block()
{
    sprite = new sf::Sprite();
    possition.x = 0;
    possition.y = 0;

    spritePos.x = 0;
    spritePos.y = 0;
    
    size.x = 10;
    size.y = 10;

    scale.x = 1.0f;
    scale.y = 1.0f;

    updateSprite();
}

Block::Block(sf::Texture t, sf::Vector2f p)
{
    // this needs to be tested
    texture = &t;

    sprite = new sf::Sprite(t);

    possition = p;

    spritePos.y = 0;
    spritePos.x = 105;

    size.y = 100;
    size.x = 100;

    scale.x = 0.1f;
    scale.y = 0.1f;

    updateSprite();
}

Block::~Block()
{
    delete sprite;
}

void Block::updateSprite()
{
    sprite->setTexture(*texture);
    sprite->setPosition(possition);
    sprite->setTextureRect(sf::IntRect(spritePos, size));
    sprite->scale(scale);
}

void Block::setPossition(sf::Vector2f p)
{
    possition = p;

    sprite->setPosition(possition);
}

void Block::setTexture(sf::Texture t)
{
    texture = &t;

    sprite->setTexture(*texture);
}

void Block::setTexturePos(sf::Vector2i p)
{
    spritePos = p;

    sprite->setTextureRect(sf::IntRect(spritePos, size));
}

void Block::setSize(sf::Vector2i f)
{
    size = f;

    sprite->scale(scale);
}