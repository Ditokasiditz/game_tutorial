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
#include <SFML/Audio.hpp>


const int maxwin = 15;
const int maxcoin = 27;
int random_between(int min, int max);


int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");
	srand(time(NULL));

	//sound 
	sf::SoundBuffer game;
	game.loadFromFile("./sound/01 Running About.flac");
	
	sf::SoundBuffer game1;
	game1.loadFromFile("./sound/08 Miss.flac");

	sf::SoundBuffer game2;
	game2.loadFromFile("./sound/05 Stage Clear.flac");

	sf::SoundBuffer game3;
	game3.loadFromFile("./sound/Cartoon.wav");

	sf::Sound themesong;
	themesong.setBuffer(game);
	themesong.play();

	sf::Sound coinsound;
	coinsound.setBuffer(game2);

	sf::Sound diesound;
	diesound.setBuffer(game1);

	sf::Sound hurtsound;
	hurtsound.setBuffer(game3);
	hurtsound.setVolume(30.f);

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
	std::vector<brick*> brickVec;

	brick brick;
	brick.setposition(190, 90);
	brickVec.push_back(&brick);


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
		x_coin = x_coin + 60;
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
	double msec100, msec50, msec25, msec125, msec2200;
	sf::Clock clock1sec, clock100msec, clock50msec, clock25msec, clock125msec, clock2200msec;
	sf::Time time1sec, time100msec, time50msec, time25msec, time125msec, time2200msec;
	clock1sec.restart();
	clock100msec.restart();
	clock50msec.restart();
	clock25msec.restart();
	clock125msec.restart();
	clock2200msec.restart();


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
				int xxx = event.mouseMove.x;int yyy = event.mouseMove.y;
				printf("(%d,%d)",xxx,yyy);
			}
		}

		brick.falldown();
		felix.move();
		

		//coin logic
		for (int i = 0; i < coinVec.size(); i++) {
			if (felix.isCollidingWithCoin(coinVec[i])) {
				coinsound.play();
				coinVec[i]->setposition(422234, 423432);
				score+=10;
				ssScore.str("");
				ssScore << "Score " << score;
				lblScore.setString(ssScore.str());
			}
		}
		

		//brick logic
		for (int i = 0; i < brickVec.size(); i++) {
			if (felix.isCollidingWithBrick(brickVec[i])) {
				brickVec[i]->setposition(422234, 423432);
				lifechance--;
				if (lifechance == 0)
				{
					themesong.pause();
					diesound.play();
				}
				else
					hurtsound.play();
				sslife.str("");
				sslife << "Lifes " << lifechance;
				lbllife.setString(sslife.str());
			}
		}




		window.clear();


		//time update
		time100msec = clock100msec.getElapsedTime();
		time125msec = clock125msec.getElapsedTime();
		time2200msec = clock2200msec.getElapsedTime();
		msec100 = time100msec.asMilliseconds();
		msec125 = time125msec.asMilliseconds();
		msec2200 = time2200msec.asMilliseconds();

		//reset posx brick
		if (msec2200 > 3200)
		{
			int newx_brick = random_between(150, 724);
			brick.setposition(newx_brick, 90);
			clock2200msec.restart();
		}
		//coin animation 
		if (msec125 > 125)
		{
			for (int i = 0; i < maxcoin; i++)
			{
				coin[i].animation();
				clock125msec.restart();
			}
		}

		//felix animation
		if (msec100 > 100)
		{
			felix.animation();
			clock100msec.restart();
		}



		//window draw
		window.draw(longbush);

		building.draw(window);

		for (int i = 0; i < 3; i++)
			window.draw(floor[i]);

		for (int i = 0; i < 5; i++)
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



int random_between(int min, int max)
{
	int r = (rand() / (float)RAND_MAX) * (max + 1) + min;
	return r > max ? max : r;
}