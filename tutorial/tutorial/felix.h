#pragma once
#include <SFML/Graphics.hpp>
#include "coin.h"

class felix
{
private:
	double speed;
	bool turnleft;
	bool turnright;
	bool goup;
	bool godown;
	
	sf::Texture pngsprite;
	sf::Sprite sprite;
	float spriteSizeX;
	float spriteSizeY;


public:
	
	felix();
	int animationFrame = 0;
	void move();
	void set_position(int x, int y);
	void reset_movestate();
	void animation();
	void draw(sf::RenderWindow& i_window);
	int getY();
	bool isCollidingWithCoin(coin *coin);

	

};

