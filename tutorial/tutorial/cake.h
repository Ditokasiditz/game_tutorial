#pragma once
#include <SFML\Graphics.hpp>
#include <iostream>


class cake
{
private:
	sf::Texture texture;
	sf::Sprite sprite;
public:
	cake();
	void draw(sf::RenderWindow &window);
	void setposition(int x, int y);
	int animationFrame = 0;
	void animation();

	sf::FloatRect getGlobalBounds()
	{
		return sprite.getGlobalBounds();
	}

};


