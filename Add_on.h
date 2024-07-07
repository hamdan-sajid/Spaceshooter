#include <SFML/Graphics.hpp>
#include <iostream>
using namespace sf;
class add_on
{
    public:


};
class Danger : public add_on
{
    public:
    Texture dangerz;
    Sprite danger;
    Texture dangeryy;
    Sprite dangery;
    Danger()
    {
        dangerz.loadFromFile("img/PNG/Meteors/meteorGrey_med1.png");
        danger.setTexture(dangerz);
        danger.setPosition(-100,550); 

        dangeryy.loadFromFile("img/PNG/Meteors/meteorBrown_med1.png");
        dangery.setTexture(dangeryy);
        dangery.setPosition(-100,400); 
    }


};
