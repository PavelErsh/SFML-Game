#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(800, 800), "SFML test sample!");
    
    Image hero_image;
    hero_image.loadFromFile("horse.png");
    
    Texture hero_texture;
    hero_texture.loadFromImage(hero_image);

    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(0, 160, 80, 80));
    hero_sprite.setPosition(50, 50);
    
	Clock clock;
    	
    float current_rect = 0; //frame for animation

    while (window.isOpen())
    {
		float time = clock.getElapsedTime().asMicroseconds();
		clock.restart();
        time /= 1000;

		Event event;
        while (window.pollEvent(event))
        {
		    if (event.type == Event::Closed)
                window.close();
        	}
       
			if (Keyboard::isKeyPressed(Keyboard::Right)){
				current_rect += time * 0.005;
				if (current_rect > 4){
						current_rect -= 4;
					}

				hero_sprite.move(0.1*time, 0); //move(x, y)
				hero_sprite.setTextureRect(IntRect(int(current_rect)*80, 160, 80, 80));
			}

			if (Keyboard::isKeyPressed(Keyboard::Left)){
				current_rect += time * 0.005;
				if (current_rect > 4){
						current_rect -= 4;
				}

				hero_sprite.move(-0.1*time, 0);
				hero_sprite.setTextureRect(IntRect(int(current_rect)*80, 80, 80, 80));
			}
		
			if (Keyboard::isKeyPressed(Keyboard::Up)){
				current_rect += time * 0.005;
				if (current_rect > 4){
					current_rect -= 4;
				}

				hero_sprite.move(0, -0.1*time);
				hero_sprite.setTextureRect(IntRect(int(current_rect)*80, 240, 80, 80));
			}

			if (Keyboard::isKeyPressed(Keyboard::Down)){
				current_rect += time * 0.005;
				if (current_rect > 4){
					current_rect -= 4;
				}
					hero_sprite.move(0, 0.1*time);
					hero_sprite.setTextureRect(IntRect(int(current_rect)*80, 0, 80, 80));
			}
		

        window.clear();
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}


