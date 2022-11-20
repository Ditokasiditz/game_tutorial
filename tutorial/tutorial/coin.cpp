#include "coin.h"
#include <SFML\Graphics.hpp>
#include <iostream>

coin::coin()
{
	texture.loadFromFile("./image/Coin.png");
	sprite.setTexture(texture);
	sprite.setTextureRect(sf::IntRect(0, 0, 16, 16));
	sprite.setScale(3, 3);
}

void coin::draw(sf::RenderWindow &window) 
{
	window.draw(sprite);
}


void coin::setposition(int x, int y)
{
	sprite.setPosition(x, y);
}


void coin::animation()
{
	
	sprite.setTextureRect(sf::IntRect(16 * animationFrame,0 ,16, 16));
	
	animationFrame++;

	if (animationFrame >= 10) {
		animationFrame = 0;
	}
}