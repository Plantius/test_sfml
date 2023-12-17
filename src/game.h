#ifndef GAME_H
#define GAME_H
#include <SFML/Graphics.hpp>
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

    // Private constructors
    void initGame();
    
public:
    Game(); // Constructor
    ~Game(); // Destructor

    // Render, update and handle events
    void update();
    void render();
    void handleEvents();

    // Getters
    bool isWindowOpen() const {return window->isOpen();};
    
};

#endif