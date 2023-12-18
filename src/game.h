#ifndef GAME_H
#define GAME_H
#include "constants.h"
#include "player.h"
#include <iostream>

#define WINDOW_WIDTH 1200
#define WINDOW_HEIGHT 800

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

    Player* player;
    sf::CircleShape* playerSprite;

    // Private constructors
    void initGame();
    
public:
    Game(); // Constructor
    ~Game(); // Destructor

    // Render, update and handle events
    void update();
    void render();
    void handleEvents();

    // Drawers
    void drawText(const std::string string, 
                  const sf::Color color, 
                  const int size, 
                  const sf::Vector2f position);

    // Getters
    bool isWindowOpen() const {return window->isOpen();};
    
};

#endif