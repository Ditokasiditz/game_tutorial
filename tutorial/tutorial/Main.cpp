#include <iostream>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include "felix.h"
#include "window_bg.h"
#include "building.h"
#include "coin.h"
#include "brick.h"

#include <SFML/Graphics.hpp>


const int maxwin = 15;
const int maxcoin = 27;



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
	longbush.setPosition(0,640);

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
	window_bg fixedwin[maxwin];
	for (int i = 0; i < maxwin; i++)
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


	//brick 
	brick brick;
	brick.setposition(190, 90);
	


	//felix
	felix felix;
	felix.set_position(447, 270);
	felix.animationFrame = 0;



	//coin object
	std::vector<coin*> coinVec;

	int x_coin = 200;
	int y_coin = 290;

	coin coin[maxcoin];
	for (int i = 0; i < maxcoin; i++)
	{
		coin[i].animationFrame = 0;
		coinVec.push_back(&coin[i]);
		coin[i].setposition(x_coin, y_coin);
		x_coin = x_coin+60;
		if (x_coin > 715)
		{
			x_coin = 200;
			y_coin = y_coin + 155;
		}
	}



	//Score Objects:
	int score = 0;

	sf::Font arial;
	arial.loadFromFile("ARCADECLASSIC.ttf");

	std::ostringstream ssScore;
	ssScore << "Score: " << score;

	sf::Text lblScore;
	lblScore.setCharacterSize(30);
	lblScore.setPosition({ 10, 10 });
	lblScore.setFont(arial);
	lblScore.setString(ssScore.str());



	//life Objects:
	int lifechance = 3;

	std::ostringstream sslife;
	sslife << "Lifes   " << lifechance;

	sf::Text lbllife;
	lbllife.setCharacterSize(30);
	lbllife.setPosition({ 10, 50 });
	lbllife.setFont(arial);				//define with score obj
	lbllife.setString(sslife.str());



	//timer
	double msec100, msec50, msec25, msec125;
	sf::Clock clock1sec, clock100msec, clock50msec, clock25msec, clock125msec;
	sf::Time time1sec, time100msec, time50msec, time25msec, time125msec;
	clock1sec.restart();
	clock100msec.restart();
	clock50msec.restart();
	clock25msec.restart();
	clock125msec.restart();
	

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
				//int xxx = event.mouseMove.x;int yyy = event.mouseMove.y;
				//printf("(%d,%d)",xxx,yyy);
			}			
		}

		brick.falldown();
		felix.move();
		//int xxx = felix.getX(); int yyy = felix.getY();
		//printf("(%d,%d)", xxx, yyy);


		//coin logic
		for (int i = 0; i < coinVec.size(); i++) {
			if (felix.isCollidingWithCoin(coinVec[i])) {
				coinVec[i]->setposition(422234, 423432);
				score++;
				ssScore.str("");
				ssScore << "Score " << score;
				lblScore.setString(ssScore.str());
			}
		}



		window.clear();


		//time update
		time100msec = clock100msec.getElapsedTime();
		time125msec = clock125msec.getElapsedTime();
		msec100 = time100msec.asMilliseconds();
		msec125 = time125msec.asMilliseconds();

		//coin animation 
		if(msec125 > 125)
		{
			for (int i = 0; i < maxcoin; i++)
			{
				coin[i].animation();
				clock125msec.restart();
			}
		}

		//felix animation
		if (msec100 > 100 )
		{	
			felix.animation();		
			clock100msec.restart();
		}



		//window draw
		window.draw(longbush);

		building.draw(window);

		for (int i = 0; i < 3; i++)
			window.draw(floor[i]);

		for(int i=0;i<5;i++)
			window.draw(greenwin[i]);

		for (int i = 0; i < maxwin; i++)
			fixedwin[i].draw(window);

		for (int i = 0; i < maxcoin; i++)
			coin[i].draw(window);

		window.draw(lblScore);

		window.draw(lbllife);

		felix.draw(window); ///draw sprite

		brick.draw(window);
		
		

		window.display();
	}

	return 0;
}

