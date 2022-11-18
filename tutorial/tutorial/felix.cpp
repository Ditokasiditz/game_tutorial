#include "felix.h"
#include <SFML/Graphics.hpp>


felix::felix()
{
	pngsprite.loadFromFile("./image/sprite.png");
	sprite.setTexture(pngsprite);
	sprite.setScale(0.7f, 0.7f);

	spriteSizeX = pngsprite.getSize().x / 4;
	spriteSizeY = pngsprite.getSize().y / 4;

	sprite.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));

}


void felix::move()
{
	sf::Vector2f position = sprite.getPosition();
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		if (position.x > 170.f)
		{
			turnleft = true;
			sprite.move(-speed, 0.00);
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
		if (position.y < 520.f)
		{
			godown = true;
			sprite.move(0.00, speed);
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
		if (position.y > 0)
		{
			goup = true;
			sprite.move(0.00, -speed);
		}

	if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		if (position.x < 715)
		{
			turnright = true;
			sprite.move(speed, 0.00);

		}
}




void felix::set_position(int x, int y)
{
	sprite.setPosition(x, y);
}


void felix::reset_movestate()
{
	speed = 0.25;
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



