#include <SFML/Graphics.hpp>
#include "player.h"
#include "view.h"
#include "map.h"

using namespace sf;

const int SCREEN_WIDHT = 800;
const int SCREEN_HEIGHT = 800;

int main()
{	
    Font font;
    font.loadFromFile("font/text.ttf");
    Text text("", font, 20); 
    text.setFillColor(Color::Black);
    text.setStyle(sf::Text::Bold | sf::Text::Underlined); 


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
			
			for(int  h=0; h<HEIGHT_MAP;h++)
            {
                for(int w=0; w<WIDTH_MAP; w++)
                {
                    if(TileMap[h][w]=='h')
                    {
                        map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*0, 0, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
                    }

                    if(TileMap[h][w]=='s')
                    {
                        map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*3, 0, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
                    }

                    if(TileMap[h][w]=='l')
                    {
                        map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*2, 0, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
                    }

                    if(TileMap[h][w]=='g')
                    {
                        map_sprite.setTextureRect(IntRect(WIDTH_MAP_TILE*1, 0, WIDTH_MAP_TILE, HEIGHT_MAP_TILE));
                    }
                    
                    map_sprite.setPosition(w*WIDTH_MAP_TILE, h*HEIGHT_MAP_TILE);
                    window.draw(map_sprite);
                }
            }
            
			move_cam(my_player.get_x(), my_player.get_y());
			move_map(time);

			window.draw(my_player.sprite);

            text.setString("Score:" + std::to_string( my_player.get_score()) );
            text.setPosition(view.getCenter().x + 90 , view.getCenter().y + 90);
            my_player.map_touch();
            window.draw(text);

			window.display();
    }

    return 0;
}


