#include "window_bg.h"
#include <SFML/Graphics.hpp>

window_bg::window_bg()
{
	
	fixedwindow.loadFromFile("./image/window/fixedwindow.png");
	sprite.setTexture(fixedwindow);
	sprite.setScale(2.08, 2.09);
	
}

void window_bg::setposition(int x, int y)
{
	sprite.setPosition(x, y);
}

void window_bg::draw(sf::RenderWindow& window)
	{
	window.draw(sprite);
	}