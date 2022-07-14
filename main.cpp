#include <SFML/Graphics.hpp>
#include "player.h"
#include "view.h"
#include "map.h"

using namespace sf;

const int SCREEN_WIDHT = 800;
const int SCREEN_HEIGHT = 800;

int main()
{	
	Image map_image;
	map_image.loadFromFile("images/map.png");
	Texture map_texture;
	map_texture.loadFromImage(map_image);
	Sprite map_sprite;
	map_sprite.setTexture(map_texture);

    RenderWindow window(sf::VideoMode(SCREEN_WIDHT, SCREEN_HEIGHT), "SFML test sample!");
	view.reset(sf::FloatRect(0, 0, 400, 280));
    Player my_player( "images/stone.png", 90,  90);
    
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
			window.setView(view);

			window.clear();
			
			for(int  h=0; h<HEIGHT_MAP;h++){
                for(int w=0; w<WIDTH_MAP; w++){
                    if(TileMap[h][w]=='h'){
                        map_sprite.setTextureRect(IntRect(64*0, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='s'){
                        map_sprite.setTextureRect(IntRect(64*3, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='l'){
                        map_sprite.setTextureRect(IntRect(64*2, 0, 64, 64));
                    }
                    if(TileMap[h][w]=='g'){
                        map_sprite.setTextureRect(IntRect(64*1, 0, 64, 64));
                    }
                    

                    map_sprite.setPosition(w*64, h*64);

                    window.draw(map_sprite);
                }
            }
			move_cam(my_player.get_x(), my_player.get_y());
			move_map(time);
			window.draw(my_player.sprite);
			window.display();
    }

    return 0;
}


