#ifndef PLAYER_H
#define PLAYER_H
#include "constants.h"

class Player
{
    private:
        sf::Vector2f position;
        sf::Vector2f velocity;

    public:
        Player();
        
        // Setters
        void setPosition(const sf::Vector2f pos);
        void setVelocity(const sf::Vector2f v);

        // Getters
        sf::Vector2f getPosition() const;
        sf::Vector2f getVelocity() const;
        

};


#endif