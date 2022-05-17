#include <SFML/Graphics.hpp>
using namespace sf;

class Player{

	private:

		String file_name;
		Image image;
		Texture texture;
		
		float center_x, center_y;
		float width, height;
		int derection;
		float speed;
		float change_x, change_y;
		float current_rect;
		float time;

	public:
		Sprite sprite;
		Player(String user_file, float user_center_x, float user_center_y, float user_w, float user_h);
		void update(float time);
		void control(float time);

};

Player::Player(String user_file, float user_center_x, float user_center_y, float user_w, float user_h){
	
	file_name = user_file;
	center_x = user_center_x;
	center_y = user_center_y;
	width = user_w;
	height = user_h;

	derection = 0;
	speed = 0;
	change_x = 0;
	change_y = 0;
	current_rect = 0; //frame for animation


	image.loadFromFile(file_name);//загрузили файл в изображение 
	texture.loadFromImage(image);//загружаем изображение в текстуру 

	sprite.setTexture(texture);//устанавливаем текстуру спрайту 

	sprite.setTextureRect(IntRect(0, 0, width, height)); //вырезаем первый костюм 

	sprite.setPosition( center_x, center_y ); 
}

void Player::update(float time){

	if (derection == 0)
	{
		change_x = speed;
		change_y = 0;
	}

	if (derection == 1)
	{
		change_x = -speed;
		change_y = 0;
	}

	if (derection == 2)
	{
		change_x = 0;
		change_y = speed;
	}

	if (derection == 3)
	{
		change_x = 0;
		change_y = -speed;
	}

	center_x += change_x * time;
	center_y += change_y * time;
	speed = 0;
	sprite.setPosition(center_x, center_y);
}

void Player::control(float time){
	if (Keyboard::isKeyPressed(Keyboard::Right)){
			derection = 0;
			speed = 0.1;
			current_rect += time * 0.005;

			if (current_rect > 4){
				current_rect -= 4;
			}

			sprite.setTextureRect(IntRect(80 * int(current_rect), 160, 80, 80));
		}

	if (Keyboard::isKeyPressed(Keyboard::Left)){
			derection = 1;

			speed = 0.1;
			current_rect += time*0.005;

			if( current_rect > 4){
				current_rect -= 4;
			}

			sprite.setTextureRect(IntRect(80 * int(current_rect), 80, 80, 80));	
		}
		
	if (Keyboard::isKeyPressed(Keyboard::Up)){
			derection = 3;

			speed = 0.1;

			current_rect += time*0.005;

			if( current_rect > 4){
				current_rect -= 4;
				}

			sprite.setTextureRect(IntRect(80 * int(current_rect), 240, 80, 80));
		}

	if (Keyboard::isKeyPressed(Keyboard::Down)){
			derection = 2;

			speed = 0.1;

			current_rect += time*0.005;

			if( current_rect > 4){
			current_rect -= 4;
			}

			sprite.setTextureRect(IntRect(80 * int(current_rect), 0, 80, 80));	
		}
}

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
		my_player.control( time);
		
		my_player.update(time);
        window.clear();
        window.draw(my_player.sprite);
        window.display();
    }

    return 0;
}


