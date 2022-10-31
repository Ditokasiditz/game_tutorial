#include <iostream>

#include <SFML/Graphics.hpp>

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "fixed it felix game");

	sf::Texture pngfelix;
	pngfelix.loadFromFile("felixnormalleft.png");
	sf::Sprite felix;
	felix.setTexture(pngfelix);
	felix.setScale(1.5, 1.5);
	felix.setPosition(100,100);

	sf::Texture pngbuilding;
	pngbuilding.loadFromFile("building.png");
	sf::Sprite building;
	building.setTexture(pngbuilding);
	building.setScale(1.5,1.5);
	building.setPosition(170,-970);

	sf::Texture pnglongbush;
	pnglongbush.loadFromFile("longbush.png");
	sf::Sprite longbush;
	longbush.setTexture(pnglongbush);
	longbush.setPosition(0,560);


	while (window.isOpen())
	{
		sf::Event event;
		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
				window.close();			
		}
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
			felix.move(-0.1,0.0);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::S))
			felix.move(0.0, 0.1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::W))
			felix.move(0.0, -0.1);
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
			felix.move(0.1, 0.0);

		window.clear();

		window.draw(building);
		window.draw(longbush);
		window.draw(felix);

		window.display();
	}

	return 0;
}