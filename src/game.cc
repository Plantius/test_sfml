#include "game.h"

Game::Game()
{
    initGame();
} // Default Constructor

Game::~Game()
{
    delete this->window;
} // Default Destructor

void Game::initGame() 
{   
    windowHandle.height = WINDOW_HEIGHT;
    windowHandle.width = WINDOW_WIDTH;
    windowTitle = "Test -- SFML";

    window = new sf::RenderWindow(windowHandle, windowTitle);
} // Private Constructor

/*
==================================================================
*/

void Game::handleEvents()
{
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            if (event.key.code == sf::Keyboard::Escape){
                window->close();
            }
            break;
        default:
            break;
        }
    }
} // handleEvents

void Game::update()
{

} // update

void Game::render()
{
    window->clear(sf::Color::White);
    window->display();
} // render