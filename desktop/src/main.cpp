#include <SFML/Graphics.hpp>
//#include <SFML/Audio.hpp>
//#include <SFML/Network.hpp>

#include "../../core/src/dagganaswirl/application/controllers/DagganaApp.h"

#define WIDTH 600
#define HEIGHT 800

int main (int argc, const char * argv[])
{
    // Create the main window
    sf::Window window(sf::VideoMode(WIDTH, HEIGHT), "Daggana Swirl");

    //setup dagganaswirl
    DagganaApp app(WIDTH, HEIGHT);
    
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
                app.resize(event.size.width, event.size.height);
            }
    	}

    	window.setActive();
        
        //draw dagganaswirl
        app.draw();

    	// Update the window
    	window.display();
    }

	return EXIT_SUCCESS;
}
