#include "game.h"

int main()
{
    // Creating the game object
    Game game;    

    // Rendering the window
    try
    {
        while (game.isWindowOpen())
        {
            game.update(); // Update game
            game.handleEvents(); // Handle events
            game.render(); // Render window
        }   
    }
    catch(const std::exception& e)
    {
        std::cerr << e.what() << '\n';
        return EXIT_FAILURE;
    }

    return EXIT_SUCCESS;
}