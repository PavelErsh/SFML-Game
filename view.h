#pragma once

#include <SFML/Graphics.hpp>

using namespace sf;
sf::View view;

void move_cam(float x, float y)
{
	if (x < 200)
	{
		x = 200;
	}

	if (x > 425)
	{
		x = 425;
	}

	if (y < 150)
	{
		y = 150;
	}

	if (y > 600){
		y = 600;
	}

	view.setCenter(x + 10, y + 10);
}

void move_map(float time)
{

	if (Keyboard::isKeyPressed(Keyboard::R))
	{
		view.rotate(0.01);
	}

	if (Keyboard::isKeyPressed(Keyboard::T))
	{
		view.rotate(-0.01);
	}

	if (Keyboard::isKeyPressed(Keyboard::U))
	{
		view.zoom(1.0001f);
	}

	if (Keyboard::isKeyPressed(Keyboard::Y))
	{
		view.zoom(0.9999f);
	}

	if (Keyboard::isKeyPressed(Keyboard::S))
	{
		view.setSize(640, 480);
	}
}
