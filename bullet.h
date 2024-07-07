#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace sf;
class bullet
{
public:
    Texture tex;
	Sprite bull;
    int move_x;
	int move_y;
	bool bS = 0;
	bullet()
	{
		tex.loadFromFile("img/PNG/Lasers/laserRed14.png");
		bull.setTexture(tex);
		bull.setPosition(0,-50);
	}
	
	

};
