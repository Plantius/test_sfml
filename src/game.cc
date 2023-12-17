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
    // window->setFramerateLimit(60);
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
    deltaTime = clock.restart();
    std::cout << "FPS: " << 1/deltaTime.asSeconds() << std::endl;


} // update

void Game::render()
{  
    sf::Font font;
    if (!font.loadFromFile("resources/arial.ttf")){
        std::cout << "ERROR" << std::endl;
    }
    sf::Text fps(std::to_string(static_cast<int>(1/deltaTime.asSeconds())), font, 30);
    fps.setPosition({10, 10});
    fps.setFillColor(sf::Color::Black);

    window->clear(sf::Color::White);
    window->draw(fps);
    window->display();
} // render