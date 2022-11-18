#include <iostream>
#include <typeinfo>
#include "felix.h"

#include <SFML/Graphics.hpp>



short maxwin = 15;

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");
	int k = 2;			//start chek window and felix position 

	//building
	sf::Texture pngbuilding;
	pngbuilding.loadFromFile("./image/building/building.png");
	sf::Sprite building;
	building.setTexture(pngbuilding);
	building.setScale(2,2);
	building.setPosition(151, -1366);

	//floor
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

	//broken window
	sf::Texture pngbrokenwin;
	int x_brokenwin = 205;
	int y_brokenwin = 213;
	int posx_win[15];
	int posy_win[15];
	pngbrokenwin.loadFromFile("./image/window/brokewin.png");
	sf::Sprite brokenwin[15];
	for (int i = 0; i < maxwin; i++)
	{
		brokenwin[i].setTexture(pngbrokenwin);
		brokenwin[i].setScale(1.05, 1.05);
		brokenwin[i].setPosition(x_brokenwin, y_brokenwin);
		posx_win[i] = x_brokenwin;
		posy_win[i] = y_brokenwin;
		x_brokenwin += 109;
		if (x_brokenwin > 715)
		{
			x_brokenwin = 205;
			y_brokenwin = y_brokenwin+147;
		}
	}

	
	//half window 
	sf::Texture pnghalfwin;
	pnghalfwin.loadFromFile("./image/window/halfwin.png");
	sf::Sprite halfwin;
	halfwin.setTexture(pnghalfwin);
	halfwin.setScale(1.05, 1.05);
	halfwin.setPosition(500, 500);


	//felix
	
	felix felix;
	felix.set_position(posx_win[1], posy_win[1]);
	felix.animationFrame = 0;


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
				int xxx = event.mouseMove.x;int yyy = event.mouseMove.y;
				printf("(%d,%d)",xxx,yyy);
			}
			
			
						
		}


		felix.move();



		window.clear();



		//time update
		time100msec = clock100msec.getElapsedTime();
		msec100 = time100msec.asMilliseconds();
		//felix animation
		if (msec100 > 100 )
		{	
			felix.animation();		
			clock100msec.restart();
		}
		
		window.draw(longbush);
		window.draw(building);
		for(int i=0;i<5;i++)
			window.draw(greenwin[i]);
		for (int i = 0; i < maxwin; i++)
			window.draw(brokenwin[i]);
		
		felix.draw(window); ///draw sprite
		
		

		window.display();
	}

	return 0;
}

