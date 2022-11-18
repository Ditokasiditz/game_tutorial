#include "felix.h"

#include <iostream>
void Character::Move() {



	//Up
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up)) {
		SheetX = 0;
		SheetY = 192;
		y_pos = y_pos - 1;
		Up = true;

	}
	//Down
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down)) {
		SheetX = 0;
		SheetY = 48;
		y_pos = y_pos + 1;
		Down = false;

	}
	//Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		SheetX = 0;
		SheetY = 480;
		x_pos = x_pos - 1;
		Left = true;

	}
	//Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		SheetX = 0;
		SheetY = 339;
		x_pos = x_pos + 1;
		Right = true;

	}
	//Up Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		SheetX = 334;
		SheetY = 490;

	}
	//Up Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up) and sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		SheetX = 333;
		SheetY = 340;
	}
	//Down Right
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and sf::Keyboard::isKeyPressed(sf::Keyboard::Right)) {
		SheetX = 334;
		SheetY = 48;
	}
	//Down Left
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down) and sf::Keyboard::isKeyPressed(sf::Keyboard::Left)) {
		SheetX = 334;
		SheetY = 191;
	}

}
