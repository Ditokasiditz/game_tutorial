#include <iostream>
#include <typeinfo>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(900, 700), "fixed it felix game");

	sf::Texture pngfelix;
	pngfelix.loadFromFile("felixnormalleft.png");
	sf::Sprite felix;
	felix.setTexture(pngfelix);
	felix.setScale(2, 2);
	felix.setPosition(190,100);

	sf::Texture pngbuilding;
	pngbuilding.loadFromFile("building.png");
	sf::Sprite building;
	building.setTexture(pngbuilding);
	building.setScale(2,2);
	building.setPosition(151, -1366);

	sf::Texture pnglongbush;
	pnglongbush.loadFromFile("floor.png");
	sf::Sprite longbush;
	longbush.setTexture(pnglongbush);
	longbush.setPosition(0,640);

	sf::Texture pnggreenwin;
	pnggreenwin.loadFromFile("greenwindow.png");
	sf::Sprite greenwin;
	greenwin.setTexture(pnggreenwin);
	greenwin.setScale(1.4, 1.4);
	greenwin.setPosition(207, 24);

	
	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();	
			//if (event.type == sf::Event::MouseMoved)
			//{
			//	int xxx = event.mouseMove.x;int yyy = event.mouseMove.y;
			//	printf("(%d,%d)",xxx,yyy);
			//}
						
		}
		
		sf::Vector2f position = felix.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			if (position.x > 170.f)
				felix.move(-0.10,0.00);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (position.y < 480.f)
				felix.move(0.00, 0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (position.y > 0)
				felix.move(0.00, -0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (position.x < 591)
				felix.move(0.1, 0.00);

		sf::Vector2f position_green = greenwin.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			greenwin.move(-0.10, 0.00);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
			greenwin.move(0.00, 0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
			greenwin.move(0.00, -0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			greenwin.move(0.1, 0.00);

		
		
		int x = position_green.x;
		int y = position_green.y;
		printf("(%d,%d)", x, y);
		
		
		window.clear();

		window.draw(longbush);
		window.draw(building);
		
		window.draw(greenwin);
		
		window.draw(felix);

		window.display();
	}

	return 0;
}

void felix_moveleft()
{

}