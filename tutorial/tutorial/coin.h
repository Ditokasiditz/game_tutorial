#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class coin
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	coin();
	void draw(sf::RenderWindow &window);
	void setposition(int x, int y);
	int animationFrame = 0;
	void animation();
	
	sf::FloatRect getGlobalBounds() 
	{
		return sprite.getGlobalBounds();
	}

};


