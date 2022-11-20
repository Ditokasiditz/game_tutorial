#include <iostream>
#include <typeinfo>
#include "felix.h"
#include "window_bg.h"
#include "building.h"
#include "coin.h"

#include <SFML/Graphics.hpp>





int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");

	//floorstep
	sf::Texture floorpng;
	floorpng.loadFromFile("./image/floorstep.png");
	sf::Sprite floor[3];
	int floor_x = 188;
	int floor_y = 348;
	for (int i = 0; i < 3; i++)
	{
		floor[i].setTexture(floorpng);
		floor[i].setPosition(floor_x, floor_y);
		floor[i].setScale(0.98, 1);
		floor_y = floor_y + 155;
	}



	//building
	building building;
	building.setposition(151, -1366);

	//longbush
	sf::Texture pnglongbush;
	pnglongbush.loadFromFile("./image/floor.png");
	sf::Sprite longbush;
	longbush.setTexture(pnglongbush);
	longbush.setPosition(0, 640);

	//green window
	sf::Texture pnggreenwin;
	int x_greenwin = 203;
	pnggreenwin.loadFromFile("./image/window/greenwindow.png");
	sf::Sprite greenwin[5];
	for (int i = 0; i < 5; i++)
	{
		greenwin[i].setTexture(pnggreenwin);
		greenwin[i].setScale(1.4, 1.4);
		greenwin[i].setPosition(x_greenwin, 24);
		x_greenwin += 105;
	}

	//fixed window
	int x_win = 208;
	int y_win = 227;
	window_bg fixedwin[15];
	for (int i = 0; i < 15; i++)
	{
		fixedwin[i].setposition(x_win, y_win);
		fixedwin[i].posx_win = x_win;
		fixedwin[i].posy_win = y_win;
		x_win += 109;
		if (x_win > 715)
		{
			x_win = 208;
			y_win = y_win + 155;
		}
	}



	//felix

	felix felix;
	felix.set_position(447, 270);
	felix.animationFrame = 0;


	//coin object
	std::vector<coin*> coinVec;

	int x_coin = 200;
	int y_coin = 285;
	coin coin[15];
	for (int i = 0; i < 30; i++)
	{
		coin[i].setposition(x_coin, y_coin);
		x_coin += 60;
		if (x_coin > 715)
		{
			x_coin = 200;
			y_coin = y_coin + 155;
		}
	}



	//timer
	double msec100, msec50, msec25;
	sf::Clock clock1sec, clock100msec, clock50msec, clock25msec;
	sf::Time time1sec, time100msec, time50msec, time25msec;
	clock1sec.restart();
	clock100msec.restart();
	clock50msec.restart();
	clock25msec.restart();


	//game event 
	while (window.isOpen())
	{
		felix.reset_movestate();


		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();
			if (event.type == sf::Event::MouseMoved)
			{
				int xxx = event.mouseMove.x; int yyy = event.mouseMove.y;
				printf("(%d,%d)", xxx, yyy);
			}



		}


		felix.move();



		window.clear();


		//time update
		time100msec = clock100msec.getElapsedTime();
		msec100 = time100msec.asMilliseconds();
		//felix animation
		if (msec100 > 100)
		{
			felix.animation();
			clock100msec.restart();
		}


		window.draw(longbush);
		building.draw(window);
		for (int i = 0; i < 3; i++)
			window.draw(floor[i]);
		for (int i = 0; i < 5; i++)
			window.draw(greenwin[i]);
		for (int i = 0; i < 15; i++)
			fixedwin[i].draw(window);
		for (int i = 0; i < 15; i++)
			coin[i].draw(window);


		felix.draw(window); ///draw sprite



		window.display();
	}

	return 0;
}

