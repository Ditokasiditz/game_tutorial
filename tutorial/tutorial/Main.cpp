#include <iostream>
#include <sstream>
#include <typeinfo>
#include <cstdlib>
#include "felix.h"
#include "window_bg.h"
#include "building.h"
#include "coin.h"
#include "brick.h"
#include "cake.h"

#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


const int maxwin = 15;
const int maxcoin = 27;
int random_between(int min, int max);
int cake_posy[3] = { 280,435,590 };
int multispeed;
int now_brick = 1;
int gamestate = 0;  //0=menustate  1=gameplay 

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

	sf::SoundBuffer game4;
	game4.loadFromFile("./sound/Common 12.flac");

	sf::Sound themesong;
	themesong.setBuffer(game);
	themesong.play();

	sf::Sound coinsound;
	coinsound.setBuffer(game2);

	sf::Sound diesound;
	diesound.setBuffer(game1);

	sf::Sound hurtsound;
	hurtsound.setBuffer(game3);
	hurtsound.setVolume(40.f);

	sf::Sound cakesound;
	cakesound.setBuffer(game4);
	cakesound.setVolume(70.f);

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


	//felix
	felix felix;
	felix.set_position(447, 270);
	felix.animationFrame = 0;


	//cake object
	std::vector<cake*> cakeVec;

	cake cake;
	cake.setposition(5000, 5000);
	cakeVec.push_back(&cake);
	
	//brick object
	std::vector<brick*> brickVec;

	brick brick[2];
	for (int i = 0; i < 2; i++)
	{
		brick[i].setposition(190, 80);
		brickVec.push_back(&brick[i]);
	}
	


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
	int lifechance = 5;

	std::ostringstream sslife;
	sslife << "Lifes   " << lifechance;

	sf::Text lbllife;
	lbllife.setCharacterSize(30);
	lbllife.setPosition({ 10, 50 });
	lbllife.setFont(arial);				//define with score obj
	lbllife.setString(sslife.str());



	//timer
	double msec100, msec50, msec25, msec125, msec2200,sec5, sec6,sec56;
	sf::Clock  clock100msec, clock50msec, clock25msec, clock125msec, clock2200msec, clock5sec, clock6sec, clock56sec;
	sf::Time time1sec, time100msec, time50msec, time25msec, time125msec, time2200msec, time5sec, time6sec, time56sec;
	clock100msec.restart();
	clock50msec.restart();
	clock25msec.restart();
	clock125msec.restart();
	clock2200msec.restart();
	clock5sec.restart();
	clock6sec.restart();
	clock56sec.restart();

	//game event 
	while (window.isOpen())
	{
		felix.reset_movestate();

		felix.multispeed(felix.powerspeed);

		//cake logic
		for (int i = 0; i < cakeVec.size(); i++) {
			if (felix.isCollidingWithCake(cakeVec[i])) {
				cakesound.play();
				cakeVec[i]->setposition(45555, 45555);
				felix.powerspeed++;
			}
		}


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

		for(int i=0;i<now_brick;i++)
			brick[i].falldown();
		felix.move();

		
		//coin come back
		if (score % 270 == 0)
		{
			int x_coin = 200;
			int y_coin = 290;
			for (int i = 0; i < maxcoin; i++)
			{
				coinVec.push_back(&coin[i]);
				coin[i].setposition(x_coin, y_coin);
				x_coin = x_coin + 60;
				if (x_coin > 715)
				{
					x_coin = 200;
					y_coin = y_coin + 155;
				}
			}
		}

		//coin collect logic
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
				brickVec[i]->setposition(45555,brick[i].getY()+50);
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
		time5sec = clock5sec.getElapsedTime();
		time6sec = clock6sec.getElapsedTime();
		time56sec = clock56sec.getElapsedTime();

		msec100 = time100msec.asMilliseconds();
		msec125 = time125msec.asMilliseconds();
		msec2200 = time2200msec.asMilliseconds();
		sec5 = time5sec.asSeconds();
		sec6 = time6sec.asSeconds();
		sec56 = time56sec.asSeconds();


		//level update
		//++brick speed
		if (sec5 >= 5 && sec56 < 67)
		{
			brick[0].speed = brick[0].speed * 1.08;
			clock5sec.restart();
		}
		else if(sec56 > 68)
		{
			now_brick = 2;
			brick[1].speed = brick[0].speed;
		}
		//spawn cake
		if (sec6 >= 6 && sec56 < 56)
		{
			int newx_cake = random_between(160, 704);
			int newy_cake = cake_posy[random_between(0, 2)];
			cake.setposition(newx_cake, newy_cake);
			clock6sec.restart();
		}


		//reset posx brick
		for (int i = 0; i < now_brick; i++) {
			if (brick[i].getY() >= 760)
			{
				int newx_brick = random_between(150, 724);
				brick[i].setposition(newx_brick, 80);
			}
		}
		
		//coin&cake animation 
		if (msec125 > 125)
		{
			cake.animation();
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

		cake.draw(window);

		for(int i=0;i<now_brick;i++)
			brick[i].draw(window);

		window.display();
	}

	return 0;
}



int random_between(int min, int max)
{
	int r = (rand() / (float)RAND_MAX) * (max + 1) + min;
	return r > max ? max : r;
}