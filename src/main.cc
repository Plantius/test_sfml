#include <game.h>

int main()
{
    // Creating the game object
    Game game;    

    // Rendering the window
    while (game.isWindowOpen())
    {
        game.handleEvents(); // Handle events
        game.update(); // Update game
        game.render(); // Render window
    }   

    return 0;
}