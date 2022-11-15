#include <iostream>
#include <typeinfo>

#include <SFML/Graphics.hpp>


double speed = 0.15;
short maxwin = 15;

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");


	double msec100, msec50, msec25;
	sf::Clock clock1sec, clock100msec, clock50msec, clock25msec;
	sf::Time time1sec, time100msec, time50msec, time25msec;
	clock1sec.restart();
	clock100msec.restart();
	clock50msec.restart();
	clock25msec.restart();


	//felix
	sf::Texture pngfelix;
	pngfelix.loadFromFile("./image/right.png");
	sf::Sprite felix;
	felix.setTexture(pngfelix);
	felix.setScale(2, 2);
	felix.setPosition(250,300);

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
	pngbrokenwin.loadFromFile("./image/window/brokewin.png");
	sf::Sprite brokenwin[15];
	for (int i = 0; i < maxwin; i++)
	{
		brokenwin[i].setTexture(pngbrokenwin);
		brokenwin[i].setScale(1.05, 1.05);
		brokenwin[i].setPosition(x_brokenwin, y_brokenwin);
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





	


	//game event 
	while (window.isOpen())
	{
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
		

		//felix move
		sf::Vector2f position = felix.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			if (position.x > 170.f)
				felix.move(-speed,0.00);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (position.y < 520.f)
				felix.move(0.00, speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (position.y > 0)
				felix.move(0.00, -speed);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (position.x < 715)
				felix.move(speed, 0.00);



		window.clear();


		time1sec = clock1sec.getElapsedTime();
		time100msec = clock100msec.getElapsedTime();
		time50msec = clock50msec.getElapsedTime();
		time25msec = clock25msec.getElapsedTime();

		msec100 = time100msec.asMilliseconds();
		msec50 = time50msec.asMilliseconds();
		msec25 = time25msec.asMilliseconds();

		
		window.draw(longbush);
		window.draw(building);
		for(int i=0;i<5;i++)
			window.draw(greenwin[i]);
		
		for (int i = 0; i < maxwin; i++)
			window.draw(brokenwin[i]);
		window.draw(felix);
		

		window.display();
	}

	return 0;
}

