#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include "player.h"
#include "object.h"
#include <iostream>



class Game
{
private:
    // Variables
    sf::RenderWindow* window;
    sf::VideoMode windowHandle;

    sf::Event event;
    std::string windowTitle;

    sf::Clock clock;
    sf::Time deltaTime;

    // Objects
    Player* player;
    std::vector<Coin*> coinArray;


    // Private constructors
    void initGame();
    
public:
    Game(); // Constructor
    ~Game(); // Destructor

    // Render, update and handle events
    void update();
    void render();
    void handleEvents();

    // Updates
    void updatePlayer();

    void spawnCoin();
    bool collisionCoin() const;


    // Drawers
    void drawText(const std::string string, 
                  const sf::Color color, 
                  const int size, 
                  const sf::Vector2f position);

    // Getters
    bool isWindowOpen() const {return window->isOpen();};
    
};

#endif