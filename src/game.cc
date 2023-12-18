#include "game.h"

Game::Game()
{
    initGame();
} // Default Constructor

Game::~Game()
{
    delete this->window;
    delete this->player;
    delete this->playerSprite;
} // Default Destructor

void Game::initGame() 
{   
    // Window Constructor
    windowHandle.height = WINDOW_HEIGHT;
    windowHandle.width = WINDOW_WIDTH;
    windowTitle = "Test -- SFML";
    event = {};

    window = new sf::RenderWindow(windowHandle, windowTitle);
    // window->setFramerateLimit(60);

    // Time Constructor
    clock = {};
    deltaTime = {};

    // Player
    player = new Player();
    playerSprite = new sf::CircleShape(20, 50);
    playerSprite->setFillColor(sf::Color::Green);

} // Private Constructor

/*
==================================================================
*/

void Game::handleEvents()
{
    sf::Vector2f newVelocity;
    while (window->pollEvent(event))
    {
        switch (event.type)
        {
        case sf::Event::Closed:
            window->close();
            break;
        case sf::Event::KeyPressed:
            switch (event.key.code)
            {
            case sf::Keyboard::Escape:
                window->close();
                break;

            case sf::Keyboard::Up: case sf::Keyboard::W:
                newVelocity.x = 0;
                newVelocity.y = -1*movementSpeed;
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Down: case sf::Keyboard::S:
                newVelocity.x = 0;
                newVelocity.y = movementSpeed;
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Left: case sf::Keyboard::A:
                newVelocity.x = -1*movementSpeed; 
                newVelocity.y = 0;
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Right: case sf::Keyboard::D:
                newVelocity.x = movementSpeed; 
                newVelocity.y = 0;
                player->setVelocity(newVelocity);
                break;

            default:
                break;
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
    
    playerSprite->move(player->getVelocity().x*deltaTime.asSeconds(), player->getVelocity().y*deltaTime.asSeconds());

    if(playerSprite->getPosition().x < -2*playerSprite->getRadius()){
        playerSprite->setPosition(WINDOW_WIDTH, playerSprite->getPosition().y);
    }else if(playerSprite->getPosition().x >= WINDOW_WIDTH + 2*playerSprite->getRadius()){
        playerSprite->setPosition(0, playerSprite->getPosition().y);
    }else if(playerSprite->getPosition().y < -2*playerSprite->getRadius()){
        playerSprite->setPosition(playerSprite->getPosition().x, WINDOW_HEIGHT);
    }else if(playerSprite->getPosition().y >= WINDOW_HEIGHT + 2*playerSprite->getRadius()){
        playerSprite->setPosition(playerSprite->getPosition().x, 0);
    }

} // update

void Game::render()
{  
    window->clear(sf::Color::White);

    // Display FPS
    drawText(std::to_string(static_cast<int>(1/deltaTime.asSeconds())), 
             sf::Color::Black, 24, {10, 10});
    window->draw(*playerSprite);

    window->display();
} // render

/*
==================================================================
*/

void Game::drawText(const std::string string, 
                  const sf::Color color, 
                  const int size, 
                  const sf::Vector2f position)
{
    sf::Font font;
    if (!font.loadFromFile("resources/fonts/arial.ttf")){
        throw textError("Failed to load font: \"resources/fonts/arial.ttf\" in drawText().");
    }
    sf::Text text(string, font, size);
    text.setPosition(position);
    text.setFillColor(color);
    window->draw(text);
} // drawText

/*
==================================================================
*/

