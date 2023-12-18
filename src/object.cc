#include "object.h"

Coin::Coin()
{
    position = {0, 0};
    size = 10;
    coinSprite = new sf::CircleShape(size, 50);
    coinSprite->setFillColor(sf::Color::Cyan);
    coinSprite->setPosition(this->position);
} // Default Constructor

Coin::Coin(const sf::Vector2f pos, const float radius)
{
    this->position = pos;
    this->size = radius;
    coinSprite = new sf::CircleShape(size, 50);
    coinSprite->setFillColor(sf::Color::Cyan);
    coinSprite->setPosition(this->position);
} // Custom Constructor

Coin::~Coin()
{
    delete coinSprite;
} // Default Destructor

sf::CircleShape* Coin::getSprite() const
{
    return this->coinSprite;
}