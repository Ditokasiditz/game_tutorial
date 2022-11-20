#include "felix.h"
#include <SFML/Graphics.hpp>


felix::felix()
{
	pngsprite.loadFromFile("./image/sprite.png");
	sprite.setTexture(pngsprite);
	sprite.setScale(0.6f, 0.6f);

	spriteSizeX = pngsprite.getSize().x / 4;
	spriteSizeY = pngsprite.getSize().y / 4;

	sprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

}


void felix::move()
{
	sf::Vector2f position = sprite.getPosition();

	//slow to enter the floor 
	if (((263 < position.y && position.y < 281) || (417 < position.y && position.y < 435) || (570 < position.y)) && (position.x > 714 || position.x < 150))
		speed = speed * 0.3;

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		turnleft = true;
		if ((263 < position.y && position.y < 281) || (417 < position.y && position.y < 435) || (570 < position.y))
		{
			sprite.move(-speed, 0.00);
			int xxx = sprite.getPosition().x; int yyy = sprite.getPosition().y;
			printf("(%d,%d)", xxx, yyy);
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
	{
		if (position.x > 714 || position.x < 150)
		{
			godown = true;
			sprite.move(0.00, speed*1.2);
			int xxx = sprite.getPosition().x; int yyy = sprite.getPosition().y;
			printf("(%d,%d)", xxx, yyy);
		}
		else
		{
			godown = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
	{
		if (position.x > 714 || position.x < 150)
		{
			goup = true;
			sprite.move(0.00, -speed*1.2);
			int xxx = sprite.getPosition().x; int yyy = sprite.getPosition().y;
			printf("(%d,%d)", xxx, yyy);
		}
		else
		{
			goup = true;
		}
	}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		turnright = true;
		if ( (263<position.y && position.y<281) || (417 < position.y && position.y < 435) || (570 < position.y) )
		{
			sprite.move(speed, 0.00);
			int xxx = sprite.getPosition().x; int yyy = sprite.getPosition().y;
			printf("(%d,%d)", xxx, yyy);
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
		sprite.setTextureRect(sf::IntRect((spriteSizeX - 1) * animationFrame, (spriteSizeY * 1) + 4, spriteSizeX, spriteSizeY));
	if (turnleft)
		sprite.setTextureRect(sf::IntRect((spriteSizeX - 1) * animationFrame, (spriteSizeY * 2) + 3, spriteSizeX, spriteSizeY));
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



