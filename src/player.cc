#include "player.h"

Player::Player()
{
    position = {0, 0};
    size = 20;
    playerSprite = new sf::CircleShape(size, 50);
    movementSpeed = 100;
} // Default Constructor

Player::~Player()
{
    delete playerSprite;
} // Destructor


// SETTERS
void Player::setPosition(const sf::Vector2f pos)
{
    this->position = pos;
} // setPosition

void Player::setVelocity(const sf::Vector2f v)
{
    this->velocity = v;
} // setPosition

void Player::setMovementSpeed(const float speed)
{
    this->movementSpeed = speed;
} // setMovementSpeed

// GETTERS
sf::Vector2f Player::getPosition() const
{
    return this->position;
} // getPosition

sf::Vector2f Player::getVelocity() const
{
    return this->velocity;
} // getPosition

sf::CircleShape* Player::getPlayerSprite() const
{
    return this->playerSprite;
} // getPosition

float Player::getMovementSpeed() const
{
    return this->movementSpeed;
} // getMovementSpeed