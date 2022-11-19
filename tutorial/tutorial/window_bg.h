#pragma once
#include <SFML/Graphics.hpp>

class window_bg
{
private:
	sf::Sprite sprite;
	sf::Texture fixedwindow;
	
	
public:
	window_bg();

	int posx_win;
	int posy_win;
	
	void draw(sf::RenderWindow& i_window);

	void setposition(int x,int y);
};

