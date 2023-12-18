#include "player.h"

Player::Player()
{
    position = {0, 0};
} // Default Constructor

void Player::setPosition(const sf::Vector2f pos)
{
    this->position = pos;
} // setPosition

sf::Vector2f Player::getPosition() const
{
    return this->position;
} // getPosition

void Player::setVelocity(const sf::Vector2f v)
{
    this->velocity = v;
} // setPosition

sf::Vector2f Player::getVelocity() const
{
    return this->velocity;
} // getPosition