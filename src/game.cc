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
    window->clear(sf::Color::White);

    // Display FPS
    drawText(std::to_string(static_cast<int>(1/deltaTime.asSeconds())), 
             sf::Color::Black, 24, {10, 10});


    window->display();
} // render

void Game::drawText(const std::string string, 
                  const sf::Color color, 
                  const int size, 
                  const sf::Vector2f position)
{
    sf::Font font;
    if (!font.loadFromFile("resources/fonts/arial.ttf")){
        std::cerr << "Failed to load font" << std::endl;
    }
    sf::Text text(string, font, size);
    text.setPosition(position);
    text.setFillColor(color);
    window->draw(text);
} // drawText