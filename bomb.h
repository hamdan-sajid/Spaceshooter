#include <SFML/Graphics.hpp>
#include <iostream>
#include <string.h>
using namespace sf;
class bomb
{
public:
    Texture bombz;
    Sprite bob;
    int bomb_x;
    int bomb_y;
    bool death = 0;
    Clock clock;

    bomb(const string& ss)
    {
        bombz.loadFromFile(ss);
        bob.setTexture(bombz);
        bob.setPosition(-100, 900);
    }

    void bb_fire(bomb* &bx, RenderWindow &window)
    {

        if (clock.getElapsedTime().asSeconds() < 0.03)
        {
            window.draw(bx->bob);
        }
        if (clock.getElapsedTime().asSeconds() > 0.03)
        {
            bx->bob.setPosition(bx->bob.getPosition().x, bx->bob.getPosition().y + 10);
            clock.restart();
        }
        
    }

    void dead (bomb*& bx)
    {
        if (bx->death == 1)
        {
            if (bx->bob.getPosition().y > 800)
            {
                delete bx;
                bx = nullptr;
            }
        }
    }
};