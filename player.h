#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
#include "bullet.h"
#include "Add_on.h"
using namespace std;
using namespace sf;
class Player
{
public:
	Sprite sprite;
	Texture tex;
	Clock clock;

	float speed = 0.2;
	int Health;

	Player(std::string png_path)
	{
		tex.loadFromFile(png_path);
		sprite.setTexture(tex);
		sprite.setPosition(350, 700);
		sprite.setScale(0.75, 0.75);
		Health = 3;
	}

	void fire_ak(bool &yes, int &spa, bullet *&furry)
	{
		int posit_x;
		int posit_y;
		posit_x = sprite.getPosition().x;
		posit_y = sprite.getPosition().y;
		furry->bull.setPosition(posit_x += 32, posit_y -= 50);

		if (yes == 0)
		{
			if (!furry->bS)
			{
				furry->bS = true;
				furry->move_x = furry->bull.getPosition().x;
				furry->move_y = furry->bull.getPosition().y;
			}
			if (furry->bS)
			{
				furry->move_y -= spa;
				furry->bull.setPosition(furry->move_x, furry->move_y);

				if (furry->move_y < -100)
				{
					furry->move_y = sprite.getPosition().y - 50;
					furry->move_x = sprite.getPosition().x + 32;
					yes = true;
				}
			}
		}
	}

	void fire_s(bullet *&furry, RenderWindow &window)
	{
		static bool no = 0;
		if (no == 0)
		{
			if (clock.getElapsedTime().asSeconds() < 0.003)
			{
				window.draw(furry->bull);
			}
			if (clock.getElapsedTime().asSeconds() > 0.003)
			{
				furry->bull.setPosition(furry->bull.getPosition().x, furry->bull.getPosition().y - 10);
				clock.restart();
			}
			if (furry->bull.getPosition().y < -100)
			{
				furry->bull.setPosition(sprite.getPosition().x + 32, furry->move_y = sprite.getPosition().y - 50);
				no = 1;
			}
		}
	}

	void move(std::string s)
	{
		float delta_x = 0, delta_y = 0;
		if (s == "l")
			delta_x = -1;

		else if (s == "r")
			delta_x = +1;

		else if (s == "u")
			delta_y = -1;
		else if (s == "d")
			delta_y = 1;

		delta_x *= speed;
		delta_y *= speed;

		sprite.move(delta_x, delta_y);
	}

	void wrap_arnd()
	{
		int x_axis;
		int y_axis;
		if (sprite.getPosition().x < -100)
		{
			y_axis = sprite.getPosition().y;
			sprite.setPosition(800, y_axis);
		}
		if (sprite.getPosition().x > 800)
		{
			y_axis = sprite.getPosition().y;
			sprite.setPosition(-100, y_axis);
		}
		if (sprite.getPosition().y < -100)
		{
			x_axis = sprite.getPosition().x;
			sprite.setPosition(x_axis, 800);
		}
		if (sprite.getPosition().y > 800)
		{
			x_axis = sprite.getPosition().x;
			sprite.setPosition(x_axis, -100);
		}
	}
};
