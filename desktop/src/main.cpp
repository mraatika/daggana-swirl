#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

#include "../../core/src/dagganaswirl/game/view/gameview.h"

int main (int argc, const char * argv[])
{
    // Create the main window
    sf::Window window(sf::VideoMode(600, 800), "Daggana Swirl");

    //setup dagganaswirl
    GameView gameView;
    gameView.initGL();
    
    
    // Start the game loop
    while (window.isOpen())
    {
    	// Process events
    	sf::Event event;
    	while (window.pollEvent(event))
    	{
    		// Close window : exit
    		if (event.type == sf::Event::Closed)
    			window.close();
            
    		// Escape pressed : exit
    		if (event.type == sf::Event::KeyPressed && event.key.code == sf::Keyboard::Escape)
    			window.close();
    	}

    	window.setActive();
        
        //draw dagganaswirl
        gameView.drawGL();

    	// Update the window
    	window.display();
    }

	return EXIT_SUCCESS;
}
