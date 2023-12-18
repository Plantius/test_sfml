#ifndef OBJECT_H
#define OBJECT_H
#include "constants.h"

class Coin
{
    private:
        sf::Vector2f position;
        float size;

        sf::CircleShape* coinSprite;
    public:
        Coin();
        Coin(const sf::Vector2f pos, const float size);
        ~Coin();

        // Getters
        sf::CircleShape* getSprite() const;
        sf::Vector2f getPosition() const {return coinSprite->getPosition();};

        
};  

#endif