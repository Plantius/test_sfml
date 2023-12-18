#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"

class Player
{
    private:
        sf::Vector2f position;
        sf::Vector2f velocity;

        float size;
        float movementSpeed;

        sf::CircleShape* playerSprite;

    public:
        Player();
        ~Player();
        
        // Setters
        void setPosition(const sf::Vector2f pos);
        void setVelocity(const sf::Vector2f v);
        void setMovementSpeed(const float speed);


        // Getters
        sf::Vector2f getPosition() const;
        sf::Vector2f getVelocity() const;
        sf::CircleShape* getPlayerSprite() const;
        float getMovementSpeed() const;
        

};


#endif