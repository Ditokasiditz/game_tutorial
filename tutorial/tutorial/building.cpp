#include "building.h"
#include <SFML/Graphics.hpp>

building::building()
{
	buildingtexture.loadFromFile("./image/building/building.png");
	sprite.setTexture(buildingtexture);
	sprite.setScale(0.6f, 0.6f);
	sprite.setScale(2, 2);
}


void building::setposition(int x,int y)
{
	sprite.setPosition(x, y);
}


void building::draw(sf::RenderWindow& i_window)
{
	i_window.draw(sprite);
}