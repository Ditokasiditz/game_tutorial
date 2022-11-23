#pragma once
#include "scorboard.h"
#include <string.h>
#include <sstream>
#include <iostream>
#include <string>


#define DELETE_KEY 8
#define ENTER_KEY 13
#define ESCAPE_KEY 27


class TextBox {
public:
	TextBox(int size, sf::Color color, bool select, float x, float y) {
		textbox.setCharacterSize(size);
		textbox.setFillColor(color);
		isSelected = select;
		font.loadFromFile("ARCADECLASSIC.ttf");
		textbox.setFont(font);
		textbox.setPosition(sf::Vector2f(x, y));

		if (select) {
			textbox.setString("_");
		}
		else {
			textbox.setString("");
		}
	}

	void setSelected(bool select) {
		isSelected = select;
		if (!select) {
			std::string t = text.str();
			std::string newT = "";
			for (int i = 0; i < t.length() - 1; i++) {
				newT += t[i];
			}
			textbox.setString(newT);
		}
	}

	void setLimit(bool haslimit, int lim) {
		hasLimit = haslimit;
		limit = lim;
	}

	std::string getText() {
		return text.str();
	}

	void draw(sf::RenderWindow &window) {
		window.draw(textbox);
	}

	void typedOn(sf::Event input, int *screen, sf::RenderWindow &window, int *scoresource) {
		if (isSelected) {
			int charTyped = input.text.unicode;
			if (charTyped < 128) {
				if (hasLimit) {
					if (text.str().length() <= limit) {
						inputLogic(charTyped);
					}
					else if (text.str().length() > limit && charTyped == DELETE_KEY) {
						deleteLastChar();
					}
					if (charTyped == ENTER_KEY) {
						Enter(&text.str(), scoresource);
						*screen = 0;
						
					}
				}
				else {
					inputLogic(charTyped);
				}
			}
		}
	}

	void reset() {
		while (text.str().length() > 0)
		{
			deleteLastChar();
		}
	}
private:
	sf::Clock clock;
	sf::Text textbox;
	sf::Font font;
	std::ostringstream text;
	bool isSelected = false;
	bool hasLimit = false;
	int limit;

	void inputLogic(int charTyped) {
		if (charTyped != DELETE_KEY && charTyped != ESCAPE_KEY && charTyped != ENTER_KEY) {
			text << static_cast<char>(charTyped);
		}
		else if (charTyped == DELETE_KEY) {
			if (text.str().length() > 0) {
				deleteLastChar();
			}
		}
		textbox.setString(text.str() + "_");
	}

	void deleteLastChar() {
		std::string t = text.str();
		std::string newT = "";
		for (int i = 0; i < t.length() - 1; i++) {
			newT += t[i];
		}
		text.str("");
		text << newT;

		textbox.setString(text.str());
	}

	void Enter(std::string *namesource,int *scoresource) {
		std::fstream  name("ScoreBoard.txt", std::ios::app);
		if (name.is_open()) {
			name << *scoresource << std::endl;
			name << *namesource << std::endl;
			name.close();
		}
	}
};