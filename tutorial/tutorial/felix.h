#ifndef Character_hpp
#define Character_hpp

#include <stdio.h>
#include <SFML/Graphics.hpp>
#endif /* Character_hpp */

class Character {
public:
	int health;
	int speed;
	int x_pos;
	int y_pos;
	int SheetX;
	int SheetY;
	bool Up, Down, Left, Right;
	sf::Texture texture;
	sf::Sprite sprite;

	Character(std::string image, int xlocation, int ylocation, int s, int h) {
		health = h;
		speed = s;
		x_pos = xlocation;
		y_pos = ylocation;
		texture.loadFromFile("./image/right.png");
	}
	sf::Sprite getSprite() {
		sprite.setTexture(texture);
		sprite.setPosition(x_pos, y_pos);
		sprite.setTextureRect(sf::IntRect(SheetX, SheetY, 110, 150));
		return sprite;
	}

	void Move();

};


struct Frame {
   sf::IntRect rect;
   double duration; // in seconds
};

class Animation {
   std::vector<Frame> frames;
   double totalLength;
   double totalProgress;
   sf::Sprite *target;
   public:
     Animation(sf::Sprite& target) { 
       this->target = &target;
       totalProgress = 0.0;
     }

     void addFrame(Frame&& frame) {
       frames.push_back(std::move(frame)); 
       totalLength += frame.duration; 
     }

     void update(double elapsed) {
        totalProgress += elapsed;
        double progress = totalProgress;
        for(auto frame : frames) {
           progress -= (*frame).duration;  

          if (progress <= 0.0 || &(*frame) == &frames.back())
          {
               target->setTextureRect((*frame).rect);  
               break; // we found our frame
          }
     }
};