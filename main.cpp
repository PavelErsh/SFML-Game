#include <SFML/Graphics.hpp>
#include "player.h"

using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(800, 800), "SFML test sample!");
    Player my_player("images/horse.png", 50, 25, 80,80);
    
	Clock clock;
	
    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asMicroseconds();
		time = time / 1000;	
		clock.restart();
		
		Event event;
        while (window.pollEvent(event))
        {
		    if (event.type == Event::Closed)
                window.close();
        	}

			my_player.control();
			my_player.update(time);
			my_player.run_animate(time);

			window.clear();
			window.draw(my_player.sprite);
			window.display();
    }

    return 0;
}


