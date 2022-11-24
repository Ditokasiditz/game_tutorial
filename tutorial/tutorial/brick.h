#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class brick
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
	
public:
	brick();
	float speed;
	void draw(sf::RenderWindow &window);
	void setposition(int x, int y);
	void falldown();
	int animationFrame = 0;
	//void animation();
	int getY();
	int getX();
	sf::FloatRect getGlobalBounds()
	{
		return sprite.getGlobalBounds();
	}

	void resetspeed();
};


