#include <iostream>
#include <typeinfo>

#include <SFML/Graphics.hpp>



double speed = 0.2;
short maxwin = 15;

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");


	

	//felix
	sf::Texture pngfelix;
	pngfelix.loadFromFile("./image/sprite.png");
	sf::Sprite felix;
	felix.setTexture(pngfelix);
	felix.setScale(0.7f, 0.7f);
	felix.setPosition(250,300);

	float spriteSizeX = pngfelix.getSize().x / 4;
	float spriteSizeY = pngfelix.getSize().y / 4;
	int animationFrame = 0;

	felix.setTextureRect(sf::IntRect(0, 0, spriteSizeX, spriteSizeY));


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
		
		bool turnleft = false;
		bool turnright = false;
		bool goup = false;
		bool godown = false;


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
			{
				turnleft = true;
				felix.move(-speed,0.00 );
			}
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (position.y < 520.f)
			{
				godown = true;
				felix.move(0.00, speed);
			}
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (position.y > 0)
			{
				goup = true;
				felix.move(0.00, -speed);
			}
				
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (position.x < 715)
			{
				turnright = true;
				felix.move(speed, 0.00);

			}

		
				
		



		window.clear();

		//time update
		
		time100msec = clock100msec.getElapsedTime();
		msec100 = time100msec.asMilliseconds();
	
		//felix animation
		if (msec100 > 100 )
		{	
			if(turnright)
				felix.setTextureRect(sf::IntRect((spriteSizeX-1) * animationFrame,(spriteSizeY *1) +3, spriteSizeX, spriteSizeY));
			if(turnleft)
				felix.setTextureRect(sf::IntRect((spriteSizeX-1) * animationFrame, spriteSizeY * 2, spriteSizeX, spriteSizeY));
			if(goup)
				felix.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 3, spriteSizeX, spriteSizeY));
			if(godown)
				felix.setTextureRect(sf::IntRect(spriteSizeX * animationFrame, spriteSizeY * 0, spriteSizeX, spriteSizeY));

			animationFrame++;

			if (animationFrame >= 4) {
				animationFrame = 0;
			}
			clock100msec.restart();
		}
		


		
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

