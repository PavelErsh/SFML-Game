#pragma once

#include <SFML/Graphics.hpp>
#include"view.h"
#include "map.h"

#include <iostream>

using namespace sf;

class Player
{

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

		Player(String user_file, float user_w, float user_h, float user_center_x, float user_center_y, int user_max_frame);

		void check_frame();
		void update(float time);
		void control();
		void run_animate(float time);
		void map_touch();

		float get_x();
		float get_y();

};

Player::Player(String user_file, float user_w, float user_h, float user_center_x = 200, float user_center_y = 200, int user_max_frame = 4 )
{
	
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

	image.loadFromFile(file_name);
	texture.loadFromImage(image);
	
	sprite.setTexture(texture);
	sprite.setTextureRect(IntRect(0, 0, width, height)); 
	sprite.setPosition( center_x, center_y ); 
}

void  Player::check_frame()
{
	if( current_rect > max_frame)
	{
		current_rect -= max_frame;
	}
}

void Player::update(float time)
{

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

	map_touch();
	sprite.setPosition(center_x, center_y);
}

void Player::control()
{

	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		derection = 0;
		speed = 0.1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		derection = 1;
		speed = 0.1;
	}
		
	if (Keyboard::isKeyPressed(Keyboard::Up))
	{
		derection = 3;
		speed = 0.1;
	}

	if (Keyboard::isKeyPressed(Keyboard::Down))
	{
		derection = 2;
		speed = 0.1;
	}
}

void Player::run_animate(float time)
{
	if (Keyboard::isKeyPressed(Keyboard::Right))
	{
		current_rect += time * 0.005;
		check_frame();
		sprite.setTextureRect(IntRect(width * int(current_rect), width*2, width, height));
		//sprite.setTextureRect(IntRect(240+width * int(current_rect), width*2, width, height));
	}

	if (Keyboard::isKeyPressed(Keyboard::Left))
	{
		current_rect += time*0.005;
		check_frame();
		sprite.setTextureRect(IntRect (width * int(current_rect), width, width, height)  );	
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

void Player::map_touch(){
    for(int i=center_y/HEIGHT_MAP_TILE; i<(center_y+height)/HEIGHT_MAP_TILE;i++)
	{
        for(int k=center_x/WIDTH_MAP_TILE; k<(center_x+width)/WIDTH_MAP_TILE;k++)
		{
            if(TileMap[i][k]=='s')
			{
            	if(change_y>0)
				{
					center_y = i*HEIGHT_MAP_TILE-height;
				}

				if(change_y<0)
				{
					center_y = i* HEIGHT_MAP_TILE+HEIGHT_MAP_TILE;
				}

				if(change_x>0)
				{
					center_x = k*WIDTH_MAP_TILE-width;
				}

				if(change_x<0)
				{
					center_x = k*WIDTH_MAP_TILE+WIDTH_MAP_TILE;
				}
			}

			if(TileMap[i][k]=='h')
			{
				TileMap[i][k] = 'g';
				int randomX = 1+rand()%(HEIGHT_MAP-2);
				int randomY = 1+rand()%(HEIGHT_MAP-2);
				TileMap[randomX][randomY] = 'h';
			}

			if(TileMap[i][k]=='l')
			{
				TileMap[i][k] = 'g';
			}
        }
    }
}

float Player::get_x()
{
	return center_x;
}

float Player::get_y()
{
	return center_y;
}
