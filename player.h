#pragma once
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
		int max_frame;

	public:
		Sprite sprite;
		Player(String user_file, float user_center_x, float user_center_y, float user_w, float user_h, int user_max_frame);
		void check_frame();
		void update(float time);
		void control();
		void run_animate(float time);

};

Player::Player(String user_file, float user_center_x, float user_center_y, float user_w, float user_h, int user_max_frame ){
	
	file_name = user_file;
	center_x = user_center_x;
	center_y = user_center_y;
	width = user_w;
	height = user_h;
	max_frame = user_max_frame;

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

void  Player::check_frame( ){
	if( current_rect > max_frame){
		current_rect -= max_frame;
	}
}

void Player::update(float time ){

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

void Player::control( ){
	if (Keyboard::isKeyPressed(Keyboard::Right)){
			derection = 0;
			speed = 0.1;
		}

	if (Keyboard::isKeyPressed(Keyboard::Left)){
			derection = 1;
			speed = 0.1;
		}
		
	if (Keyboard::isKeyPressed(Keyboard::Up)){
			derection = 3;
			speed = 0.1;
		}

	if (Keyboard::isKeyPressed(Keyboard::Down)){
			derection = 2;
			speed = 0.1;
		}
}

void Player::run_animate(float time){
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		current_rect += time * 0.005;

		check_frame();

		sprite.setTextureRect(IntRect(width * int(current_rect), width*2, width, height));
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		current_rect += time*0.005;

		check_frame();

		sprite.setTextureRect(IntRect(width * int(current_rect), width, width, height));	
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		current_rect += time*0.005;

		check_frame();

		sprite.setTextureRect(IntRect(width * int(current_rect), 0, width, height));	
	}

	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		current_rect += time*0.005;

		check_frame();

		sprite.setTextureRect(IntRect(width * int(current_rect), height*3, width, height));
	}
}
