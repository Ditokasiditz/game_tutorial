#include "brick.h"
#include <SFML\Graphics.hpp>
#include <iostream>

brick::brick()
{
	texture.loadFromFile("./image/entities/brick/0.png");
	sprite.setTexture(texture);
	sprite.setScale(2.75, 2.75);
	speed = 0.44;
}

void brick::draw(sf::RenderWindow &window)
{
	window.draw(sprite);
}


void brick::setposition(int x, int y)
{
	sprite.setPosition(x, y);
}

void brick::falldown()
{
	sprite.move(0.00, speed);
}


int brick::getY()
{
	return sprite.getPosition().y;
}

int brick::getX()
{
	return sprite.getPosition().x;
}