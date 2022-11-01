#include <iostream>
#include <typeinfo>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "fixed it felix game");

	sf::Texture pngfelix;
	pngfelix.loadFromFile("felixnormalleft.png");
	sf::Sprite felix;
	felix.setTexture(pngfelix);
	felix.setScale(1.5, 1.5);
	felix.setPosition(190, 100);

	sf::Texture pngbuilding;
	pngbuilding.loadFromFile("building.png");
	sf::Sprite building;
	building.setTexture(pngbuilding);
	building.setScale(1.5, 1.5);
	building.setPosition(170, -970);

	sf::Texture pnglongbush;
	pnglongbush.loadFromFile("longbush.png");
	sf::Sprite longbush;
	longbush.setTexture(pnglongbush);
	longbush.setPosition(0, 560);


	while (window.isOpen())
	{
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

		sf::Vector2f position = felix.getPosition();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			if (position.x > 170.f)
				felix.move(-0.10, 0.00);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			if (position.y < 480.f)
				felix.move(0.00, 0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			if (position.y > 0)
				felix.move(0.00, -0.10);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			if (position.x < 591)
				felix.move(0.1, 0.00);

		window.clear();

		window.draw(building);
		window.draw(longbush);
		window.draw(felix);

		window.display();
	}

	return 0;
}

void felix_moveleft()
{

}