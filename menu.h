#include <SFML/Graphics.hpp>
#include <iostream>
#include "game.h"
#include <string.h>
class Menu
{
public:
    Game g;
    Clock clock;
    Sprite play;
    Texture p;
    Sprite help;
    Texture h;
    // add menu attributes here
    Menu()
    {
        p.loadFromFile("img/1920x1080-black-solid-color-background.jpg");
        play.setTexture(p);
        h.loadFromFile("img/17498.jpg");
        help.setTexture(h);
        // constructors body
    }

    void display_menu()

    {
        RenderWindow window(VideoMode(780, 780), title);
        Event e;
        for (;;)
        {
            window.draw(play);
            window.display();
            window.pollEvent(e);
            if (e.key.code == Keyboard::Num1)
            {
                window.close();
                g.start_game();
                break;
            }
            if (e.key.code == Keyboard::Num3)
            {
                for(;;)
                {
                    Event rr;
                    window.draw(help);
                    window.display();
                    window.pollEvent(rr);
                    if (rr.key.code == Keyboard::H)
                    {
                        break;
                    }
                }
            }
            if (e.key.code == Keyboard::Num4)
            {
                window.close();
                break;
            }
        }
    }
};
