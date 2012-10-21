#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

#include "../../core/src/dagganaswirl/game/view/gameview.h"
#include "../../core/src/dagganaswirl/application/controllers/DagganaApp.h"

int main (int argc, const char * argv[])
{
    // Create the main window
    sf::Window window(sf::VideoMode(600, 800), "Daggana Swirl");

    //setup dagganaswirl
    DagganaApp app;
    app.getGameView()->initGL();
    
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
            
            //screen resized
            if (event.type == sf::Event::Resized)
            {
                app.getGameView()->resizeGL(event.size.width, event.size.height);
            }
    	}

    	window.setActive();
        
        //draw dagganaswirl
        app.getGameView()->drawGL();

    	// Update the window
    	window.display();
    }

	return EXIT_SUCCESS;
}
