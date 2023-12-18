#include "game.h"

Game::Game()
{
    initGame();
} // Default Constructor

Game::~Game()
{
    for (size_t i = 0; i < coinArray.size(); i++){
        delete coinArray[i];
    }
    coinArray.clear();

    delete this->window;
    delete this->player;
} // Default Destructor

void Game::initGame() 
{   
    // Window Constructor
    windowHandle.height = WINDOW_HEIGHT;
    windowHandle.width = WINDOW_WIDTH;
    windowTitle = "Test -- SFML";
    event = {};

    window = new sf::RenderWindow(windowHandle, windowTitle);
    window->setFramerateLimit(60);

    // Time Constructor
    clock = {};
    deltaTime = {};

    // Player
    player = new Player();
    player->getPlayerSprite()->setFillColor(sf::Color::Green);

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
                newVelocity.y = -player->getMovementSpeed();
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Down: case sf::Keyboard::S:
                newVelocity.x = 0;
                newVelocity.y = player->getMovementSpeed();
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Left: case sf::Keyboard::A:
                newVelocity.x = -player->getMovementSpeed(); 
                newVelocity.y = 0;
                player->setVelocity(newVelocity);
                break;
            case sf::Keyboard::Right: case sf::Keyboard::D:
                newVelocity.x = player->getMovementSpeed(); 
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

/*
==================================================================
*/

void Game::update()
{
    deltaTime = clock.restart();
    std::srand(static_cast<int>(1000/deltaTime.asSeconds())); // Pseudo-random numbers

    sf::CircleShape* playerSprite = player->getPlayerSprite();
    
    playerSprite->move(player->getVelocity().x*deltaTime.asSeconds(), 
                       player->getVelocity().y*deltaTime.asSeconds());

    updatePlayer();
    if (coinArray.size() < MAX_COINS){
        spawnCoin();
    }


} // update

void Game::updatePlayer()
{
    // If player goes beyond bounds, teleport to the opposite side
    sf::CircleShape* playerSprite = player->getPlayerSprite();
    const sf::Vector2f pos = player->getPosition();
    const float radius = playerSprite->getRadius();

    if(pos.x < -2*radius){
        playerSprite->setPosition(WINDOW_WIDTH, pos.y);
    }else if(pos.x >= WINDOW_WIDTH + radius){
        playerSprite->setPosition(-radius, pos.y);
    }else if(pos.y < -2*radius){
        playerSprite->setPosition(pos.x, WINDOW_HEIGHT);
    }else if(pos.y >= WINDOW_HEIGHT + radius){
        playerSprite->setPosition(pos.x, -radius);
    }
}

void Game::spawnCoin()
{  
    Coin* coin = new Coin({std::rand() % WINDOW_WIDTH, std::rand() % WINDOW_HEIGHT}, 10);
    coinArray.push_back(coin);
    std::cout << coin->getPosition().x << "," << coin->getPosition().y << std::endl;
} // spawnCoin

bool Game::collisionCoin() const
{

} // collisionCoin


/*
==================================================================
*/

void Game::render()
{  
    window->clear(sf::Color::White);

    // Display FPS
    drawText(std::to_string(static_cast<int>(1/deltaTime.asSeconds())), 
             sf::Color::Black, 24, {10, 10});
    window->draw(*player->getPlayerSprite());
    for(size_t i = 0; i < coinArray.size(); i++){
        window->draw(*coinArray[i]->getSprite());
    }
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

