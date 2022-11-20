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

void coin::setPos(sf::Vector2f newPos)
{
	sprite.setPosition(newPos);
}

void coin::setposition(int x, int y)
{
	sprite.setPosition(x, y);
}