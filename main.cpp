#include <SFML/Graphics.hpp>
using namespace sf;

int main()
{
    RenderWindow window(sf::VideoMode(600, 600), "SFML test sample!");
    
    Image hero_image;
    hero_image.loadFromFile("horse.png");
    
    Texture hero_texture;
    hero_texture.loadFromImage(hero_image);

    Sprite hero_sprite;
    hero_sprite.setTexture(hero_texture);
    hero_sprite.setTextureRect(IntRect(0, 160, 80, 80));
    hero_sprite.setPosition(50, 50);
   

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
		    if (event.type == Event::Closed)
                window.close();
        }
       
		if (Keyboard::isKeyPressed(Keyboard::Right)){
				hero_sprite.move(0.1, 0); //move(x, y)
				hero_sprite.setTextureRect(IntRect(0, 160, 80, 80));
		}

		if (Keyboard::isKeyPressed(Keyboard::Left)){
				hero_sprite.move(-0.1, 0);
				hero_sprite.setTextureRect(IntRect(0, 80, 80, 80));
		}
		
		if (Keyboard::isKeyPressed(Keyboard::Up)){
				hero_sprite.move(0, -0.1);
				hero_sprite.setTextureRect(IntRect(0, 240, 80, 80));
		}

		if (Keyboard::isKeyPressed(Keyboard::Down)){
				hero_sprite.move(0, 0.1);
				hero_sprite.setTextureRect(IntRect(0, 0, 80, 80));
		}
		

        window.clear();
        window.draw(hero_sprite);
        window.display();
    }

    return 0;
}


