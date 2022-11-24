#include "felix.h"
#include <SFML/Graphics.hpp>
#include <math.h>


felix::felix()
{
	pngsprite.loadFromFile("./image/sprite.png");
	sprite.setTexture(pngsprite);
	sprite.setScale(0.6f, 0.6f);
	powerspeed = 0;


	spriteSizeX = pngsprite.getSize().x / 4;
	spriteSizeY = pngsprite.getSize().y / 4;

	sprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

}


void felix::move()
{
	sf::Vector2f position = sprite.getPosition();

	//slow to enter the floor 
	if (((263 < position.y && position.y < 281) || (417 < position.y && position.y < 435) || (570 < position.y)) && (position.x > 714 || position.x < 150))
		speed = 0.09;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		turnleft = true;
		if ((263 < position.y && position.y < 281) || (417 < position.y && position.y < 435) || (573 < position.y))
		{
			sprite.move(-speed, 0.00);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		godown = true;
		if (position.x > 714 || position.x < 150)
		{
			sprite.move(0.00, speed*1.2);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		goup = true;
		if (position.x > 714 || position.x < 150)
		{
			sprite.move(0.00, -speed*1.2);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		turnright = true;
		if ( (263<position.y && position.y<281) || (417 < position.y && position.y < 435) || (573 < position.y) )
		{
			sprite.move(speed, 0.00);
		}
	}


	//check limit map move 
	if (position.x > 724)
		sprite.setPosition(724, position.y);
	else if (position.x < 140)
		sprite.setPosition(140, position.y);
	
	if (position.y > 590)
		sprite.setPosition(position.x, 590);
	else if (position.y < 50)
		sprite.setPosition(position.x, 50);

}



void felix::set_position(int x, int y)
{
	sprite.setPosition(x, y);
}


void felix::reset_movestate()
{
	speed = 0.28;
	turnleft = false;
	turnright = false;
	goup = false;
	godown = false;
}
	

void felix::animation()
{
	if (turnright)
		sprite.setTextureRect(sf::IntRect((spriteSizeX) * animationFrame-2, (spriteSizeY * 1) + 4, spriteSizeX, spriteSizeY));
	if (turnleft)
		sprite.setTextureRect(sf::IntRect((spriteSizeX) * animationFrame-2, (spriteSizeY * 2) + 3, spriteSizeX, spriteSizeY));
	if (goup)
		sprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
	if (godown)
		sprite.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, spriteSizeX, spriteSizeY));
	
	animationFrame++;

	if (animationFrame >= 4) {
		animationFrame = 0;
	}
}


void felix::draw(sf::RenderWindow& i_window)
{
	i_window.draw(sprite);
}

int felix::getY() 
{
	return sprite.getPosition().y;
}

int felix::getX()
{
	return sprite.getPosition().x;
}

bool felix::isCollidingWithCoin(coin *coin) {
	if (sprite.getGlobalBounds().intersects(coin->getGlobalBounds())) {
		return true;
	}
	return false;
}


bool felix::isCollidingWithBrick(brick *brick) {
	if (sprite.getGlobalBounds().intersects(brick->getGlobalBounds())) {
		return true;
	}
	return false;
}


bool felix::isCollidingWithCake(cake *cake) {
	if (sprite.getGlobalBounds().intersects(cake->getGlobalBounds())) {
		return true;
	}
	return false;
}


void felix::multispeed()
{
	speed = speed * pow(1.2,powerspeed);
}

