#include <SFML/Graphics.hpp>
#include "player.h"
using namespace sf;

const int HEIGHT_MAP = 8;//размер карты высота 
const int WIDTH_MAP = 10;//размер карты ширина 

sf::String TileMap[HEIGHT_MAP] = {

"ssssssssss",

"sggggggggs",

"sgghgggggs",

"sggggggggs",

"sggggggggs",

"sggggglggs",

"sggggggggs",

"ssssssssss"

}; 

int main()
{	
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map_texture;
	map_texture.loadFromImage(map_image);
	Sprite map_sprite;
	map_sprite.setTexture(map_texture);

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

			for (int i = 0; i < HEIGHT_MAP; i++){
				for (int j = 0; j < WIDTH_MAP; j++){
					if (TileMap[i][j] == 'h'){

						map_sprite.setTextureRect(IntRect(64*0, 0, 64, 64));
					}

					if (TileMap[i][j] == 'g'){

						map_sprite.setTextureRect(IntRect(64*1, 0, 64, 64));
					}

					if (TileMap[i][j] == 'l'){

						map_sprite.setTextureRect(IntRect(64*2, 0, 64, 64));
						}

					if (TileMap[i][j] == 's'){

					map_sprite.setTextureRect(IntRect(64*3, 0, 64, 64));
					}

					map_sprite.setPosition(j * 64, i * 64);

					window.draw(map_sprite);
				}
			}

			window.draw(my_player.sprite);
			window.display();
    }

    return 0;
}


