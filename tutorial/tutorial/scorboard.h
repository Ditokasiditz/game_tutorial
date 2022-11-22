#pragma once
#include <fstream>
#include <iostream>
#include <vector>
#include "SFML/Graphics.hpp"


class FontText {
public:
	sf::Font font;
	sf::Text text;
	sf::Vector2f pos;
	FontText(std::string fontsource, std::string textsource, float x, float y, sf::Color color, int size) {
		font.loadFromFile(fontsource);
		text.setFont(font);
		text.setString(textsource);
		text.setPosition(sf::Vector2f(x, y));
		text.setFillColor(color);
		text.setCharacterSize(size);
	}

	void settext(std::string textSource) {
		text.setString(textSource);
	}

	void setpos(sf::Vector2f pos) {
		text.setPosition(pos);
	}
};


class scoreboard {
public:
	void showscore(sf::RenderWindow &window) {
		FontText head = FontText("ARCADECLASSIC.ttf", "top 5 scoreboard sushi", 370, 86, sf::Color::Cyan, 40);

		int pointss;
		std::string name;
		std::string textString;
		std::string pointString;
		infile.open("ScoreBoard.txt");


		while (std::getline(infile, pointString))
		{
			std::getline(infile, name);
			pointss = std::stoi(pointString);
			Point.push_back(pointss);
			Name.push_back(name);

			countline++;
			name = "";
			pointString = "";
			pointss = 0;
		}

		for (int i = 0; i < countline; i++) {
			for (int j = 0; j < countline; j++) {
				if (Point[i] > Point[j]) {
					int temp = Point[i];
					Point[i] = Point[j];
					Point[j] = temp;

					std::string txt = Name[i];
					Name[i] = Name[j];
					Name[j] = txt;
				}
			}
		}

		for (int i = 0; i < countline; i++) {
			if (i <= 4) {
				std::string point_string = std::to_string(Point[i]);
				FontText txt = FontText("ARCADECLASSIC.ttf", Name[i], 300, 174 + (60 * i), sf::Color::White, 40);
				window.draw(txt.text);
				FontText txt_t = FontText("ARCADECLASSIC.ttf", point_string, 500, 174 + (60 * i), sf::Color::White, 40);
				window.draw(txt_t.text);
			}
		}

		countline = 0;
		Point.clear();
		Name.clear();
		infile.close();
	}
private:
	std::ifstream infile;
	std::vector<int> Point;
	std::vector<std::string> Name;
	int countline = 0;
};



