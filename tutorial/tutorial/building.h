#pragma once
#include <SFML/Graphics.hpp>

class building
{
private:
	sf::Sprite sprite;
	sf::Texture buildingtexture;

public:
	building();
	void setposition(int x, int y);
	void draw(sf::RenderWindow& i_window);
};

