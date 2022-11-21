#pragma once
#include <SFML/Graphics.hpp>
#include "coin.h"
#include "brick.h"
#include "cake.h"

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
	void animation();
	void move();
	void set_position(int x, int y);
	void reset_movestate();
	void draw(sf::RenderWindow& i_window);
	int getY();
	int getX();
	bool isCollidingWithCoin(coin *coin);
	bool isCollidingWithBrick(brick *brick);
	bool isCollidingWithCake(cake *cake);
	void multispeed(int x);
	int powerspeed;
	

};

