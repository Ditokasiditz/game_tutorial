#include "cake.h"
#include <SFML\Graphics.hpp>
#include <iostream>

cake::cake()
{
	texture.loadFromFile("./image/spritecake.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 20, 21));
	sprite.setScale(3, 3);
}

void cake::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}


void cake::setposition(int x, int y)
{
	sprite.setPosition(x, y);
}


void cake::animation()
{

	sprite.setTextureRect(sf::IntRect(20 * animationFrame, 0, 20, 21));
	animationFrame++;

	if (animationFrame >= 2) {
		animationFrame = 0;
	}
}